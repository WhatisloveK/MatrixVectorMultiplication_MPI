#include "matrix_multiplicator.h"
#include "row_wise_multiplicator.h"

RowWiseMatrixMultiplicator::RowWiseMatrixMultiplicator(double* pMatrix, int size, int ProcNum, int ProcRank)
{
}

// Function for distribution of the initial data between the processes
void RowWiseMatrixMultiplicator::DataDistribution(double* pMatrix, double* pProcParts, double* pVector, int Size, int PartNum)
{
	int* pSendNum; // Number of elements sent to the process
	int* pSendInd; // Index of the first data element sent to the process
	int RestParts = Size; // Number of parts, that haven�t been distributed yet
	MPI_Bcast(pVector, Size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	// Alloc memory for temporary objects
	pSendInd = new int[ProcNum];
	pSendNum = new int[ProcNum];
	// Define the disposition of the matrix parts for current process
	PartNum = (Size / ProcNum);
	pSendNum[0] = PartNum * Size;
	pSendInd[0] = 0;
	for (int i = 1; i < ProcNum; i++) {
		RestParts -= PartNum;
		PartNum = RestParts / (ProcNum - i);
		pSendNum[i] = PartNum * Size;
		pSendInd[i] = pSendInd[i - 1] + pSendNum[i - 1];
	}
	// Scatter the parts
	MPI_Scatterv(pMatrix, pSendNum, pSendInd, MPI_DOUBLE, pProcParts,
		pSendNum[ProcRank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
	// Free the memory
	delete[] pSendNum;
	delete[] pSendInd;
}

RowWiseMatrixMultiplicator::~RowWiseMatrixMultiplicator()
{
}
