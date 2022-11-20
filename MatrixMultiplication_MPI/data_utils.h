#pragma once
class DataUtils {
public:
	void DummyDataInitialization(double* pMatrix, double* pVector, int Size);
	void RandomDataInitialization(double* pMatrix, double* pVector, int Size);
	void PrintMatrix(double* pMatrix, int RowCount, int ColCount);
	void PrintVector(double* pVector, int Size);
	void TestDistribution(double* pMatrix, double* pVector, double* pProcRows, int Size, int RowNum);
};

