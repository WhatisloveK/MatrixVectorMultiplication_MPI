#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <mpi.h>
#include <chrono>
#include "data_utils.h"
#include "matrix_multiplicator.h"
#include "row_wise_multiplicator.h"

// Function for memory allocation and data initialization
void ProcessInitialization(double* pMatrix, double* pVector,
	double*& pResult, double*& pProcRows, double*& pProcResult,
	int& Size, int& RowNum) {
	int RestRows; // Number of rows, that haven�t been distributed yet
	int i; // Loop variable
	
	
	// Determine the number of matrix rows stored on each process
	/*RestRows = Size;
	for (i = 0; i < ProcRank; i++)
		RestRows = RestRows - RestRows / (ProcNum - i);
	RowNum = RestRows / (ProcNum - ProcRank);*/
	// Memory allocation
	pVector = new double[Size];
	pResult = new double[Size];
	pProcRows = new double[RowNum * Size];
	pProcResult = new double[RowNum];
	// Setting the values of the matrix and vector elements
}

//int main(int argc, char* argv[]) {
//	double* pMatrix; // First argument - initial matrix
//	double* pVector; // Second argument - initial vector
//	double* pResult; // Result vector for matrix-vector multiplication
//	int Size; // Sizes of initial matrix and vector
//	double* pProcRows; // Stripe of the matrix on the current process
//	double* pProcResult; // Block of the result vector on the current process
//	int RowNum; // Number of rows in the matrix stripe
	
//	int ProcNum = 0; // Number of available processes
//	int ProcRank = 0; // Rank of current process
//	double Start, Finish, Duration, SerialStart, SerialFinish, c;

//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
//	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

//	MatrixMultiplicator multiplicator = RowWiseMatrixMultiplicator(pMatrix, size, ProcNum, ProcRank);
//	if (ProcRank == 0) {
//		setvbuf(stdout, 0, _IONBF, 0);
//		printf("Parallel matrix-vector multiplication program\n");
//		do {
//			printf("\nEnter the size of the matrix and vector: ");
//			scanf_s("%d", &Size);
//			if (Size < ProcNum) {
//				printf("Size of the objects must be greater than number of processes!\n ");
//			}
//		} while (Size < ProcNum);
//		pMatrix = new double[Size * Size];
//		// Initial matrix exists only on the root process
//		DataUtils dataUtils;
//		dataUtils.DummyDataInitialization(pMatrix, pVector, Size);
//		//RandomDataInitialization(pMatrix, pVector, Size);
//	}
//	MPI_Bcast(&Size, 1, MPI_INT, 0, MPI_COMM_WORLD);
	



//	// Memory allocation and data initialization
//	ProcessInitialization(pMatrix, pVector, pResult, pProcRows, pProcResult, Size, RowNum);

//	PrintMatrix(pMatrix, Size, Size);
//	Start = MPI_Wtime();
//	// Distributing the initial data between the processes
//	DataDistribution(pMatrix, pProcRows, pVector, Size, RowNum);
//	// Parallel matrix-vector multiplication
//	ParallelResultCalculation(pProcRows, pVector, pProcResult, Size, RowNum);
//	// Result replication
//	ResultReplication(pProcResult, pResult, Size, RowNum);
//	Finish = MPI_Wtime();
//	Duration = Finish - Start;
//	if (ProcRank == 0) {
//		SerialStart = MPI_Wtime();
//		TestResult(pMatrix, pVector, pResult, Size);
//		SerialFinish = MPI_Wtime();
//		SerialFinish = SerialFinish - SerialStart;
//		printf("Time of parallel execution = %f\n", Duration);
//		printf("Time of serial execution = %f\n", SerialFinish);
//	}
//	// Process termination
//	ProcessTermination(pMatrix, pVector, pResult, pProcRows, pProcResult);
//	MPI_Finalize();
//	return 0;
//}