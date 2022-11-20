#pragma once
#include<iostream>
#include<mpi.h>

class MatrixMultiplicator {
protected:
	const double* pMatrix;// First argument - initial matrix
	double* pVector; // Second argument - initial vector
	double* pResult; // Result vector for matrix-vector multiplication
	int Size; // Sizes of initial matrix and vector
	double* pProcParts; // Stripe of the matrix on the current process
	double* pProcResult; // Block of the result vector on the current process
	int PartNum; // Number of rows in the matrix stripe
	int ProcNum = 0; // Number of available processes
	int ProcRank = 0; // Rank of current process

public:
	MatrixMultiplicator();
	MatrixMultiplicator(double* pMatrix, int size, int ProcNum, int ProcRank);
	void virtual DataDistribution(double* pMatrix, double* pProcParts, double* pVector, int Size, int PartNum) = 0;
	~MatrixMultiplicator();
};

