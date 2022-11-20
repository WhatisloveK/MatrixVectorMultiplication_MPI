#pragma once

#include "matrix_multiplicator.h";

class RowWiseMatrixMultiplicator : public MatrixMultiplicator {
public:
	RowWiseMatrixMultiplicator(double* pMatrix, int size, int ProcNum, int ProcRank);
	void DataDistribution(double* pMatrix, double* pProcParts, double* pVector, int Size, int Partum);
	~RowWiseMatrixMultiplicator();
};