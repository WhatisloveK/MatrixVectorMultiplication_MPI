#include "data_utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void DataUtils::DummyDataInitialization(double* pMatrix, double* pVector, int Size) {
	int i, j; // Loop variables
	for (i = 0; i < Size; i++) {
		pVector[i] = 1;
		for (j = 0; j < Size; j++)
			pMatrix[i * Size + j] = i;
	}
}

void DataUtils::RandomDataInitialization(double* pMatrix, double* pVector, int Size) {
	int i, j; // Loop variables
	srand(unsigned(clock()));
	for (i = 0; i < Size; i++) {
		pVector[i] = rand() / double(1000);
		for (j = 0; j < Size; j++)
			pMatrix[i * Size + j] = rand() / double(1000);
	}
}

void DataUtils::PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
	int i, j; // Loop variables
	for (i = 0; i < RowCount; i++) {
		for (j = 0; j < ColCount; j++)
			printf("%7.4f ", pMatrix[i * ColCount + j]);
		printf("\n");
	}
}

void DataUtils::PrintVector(double* pVector, int Size) {
	int i;
	for (i = 0; i < Size; i++)
		printf("%7.4f ", pVector[i]);
}



//void DataUtils::TestDistribution(double* pMatrix, double* pVector, double* pProcRows,
//	int Size, int RowNum) {
//	if (ProcRank == 0) {
//		printf("Initial Matrix: \n");
//		PrintMatrix(pMatrix, Size, Size);
//		printf("Initial Vector: \n");
//		PrintVector(pVector, Size);
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	for (int i = 0; i < ProcNum; i++) {
//		if (ProcRank == i) {
//			printf("\nProcRank = %d \n", ProcRank);
//			printf(" Matrix Stripe:\n");
//			PrintMatrix(pProcRows, RowNum, Size);
//			printf(" Vector: \n");
//			PrintVector(pVector, Size);
//		}
//		MPI_Barrier(MPI_COMM_WORLD);
//	}
//}
//
//// Fuction for testing the multiplication of matrix stripe and vector
//void TestPartialResults(double* pProcResult, int RowNum) {
//	int i; // Loop variables
//	for (i = 0; i < ProcNum; i++) {
//		if (ProcRank == i) {
//			printf("\nProcRank = %d \n Part of result vector: \n", ProcRank);
//			PrintVector(pProcResult, RowNum);
//		}
//		MPI_Barrier(MPI_COMM_WORLD);
//	}
//}
//// Fuction for testing the multiplication of matrix stripe and vector
//void TestPartialResults(double* pProcResult, int RowNum) {
//	int i; // Loop variables
//	for (i = 0; i < ProcNum; i++) {
//		if (ProcRank == i) {
//			printf("\nProcRank = %d \n Part of result vector: \n", ProcRank);
//			PrintVector(pProcResult, RowNum);
//		}
//		MPI_Barrier(MPI_COMM_WORLD);
//	}
//}