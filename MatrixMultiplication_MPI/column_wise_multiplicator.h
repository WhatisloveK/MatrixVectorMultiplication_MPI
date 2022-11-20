#pragma once

#include "matrix_multiplicator.h"

class ColumnWiseMatrixMultiplicator : public MatrixMultiplicator {
public:
	ColumnWiseMatrixMultiplicator();
    ColumnWiseMatrixMultiplicator(double* pMatrix, int size, int ProcNum, int ProcRank);
    void DataDistribution(double* pMatrix, double* pProcRows, double* pVector, int Size, int RowNum);
    ~ColumnWiseMatrixMultiplicator();
};
