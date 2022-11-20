#include "column_wise_multiplicator.h"

ColumnWiseMatrixMultiplicator::ColumnWiseMatrixMultiplicator(double* pMatrix, int size, int ProcNum, int ProcRank) {
	this->pMatrix = pMatrix;
	this->Size = size;
	this->ProcNum = ProcNum;
	this->ProcRank = ProcRank;
}

void ColumnWiseMatrixMultiplicator::DataDistribution(double* pMatrix, double* pProcColumns, double* pVector, int Size, int ColumnNum)
{
    int* pSendNum; // Number of elements sent to the process
    int* pSendInd; // Index of the first data element sent to the process
    int RestColumns = Size; // Number of columns, that haven't been distributed yet
    MPI_Bcast(pVector, Size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    // Alloc memory for temporary objects
    pSendInd = new int[ProcNum];
    pSendNum = new int[ProcNum];
    // Define the disposition of the matrix columns for current process
    ColumnNum = (Size / ProcNum);
    pSendNum[0] = ColumnNum * Size;
    pSendInd[0] = 0;
    for (int i = 1; i < ProcNum; i++) {
        RestColumns -= ColumnNum;
        ColumnNum = RestColumns / (ProcNum - i);
        pSendNum[i] = ColumnNum * Size;
        pSendInd[i] = pSendInd[i - 1] + pSendNum[i - 1];
    }
    // Scatter the columns
    MPI_Scatterv(pMatrix, pSendNum, pSendInd, MPI_DOUBLE, pProcColumns,
        pSendNum[ProcRank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
    // Free the memory
    delete[] pSendNum;
    delete[] pSendInd;
}

