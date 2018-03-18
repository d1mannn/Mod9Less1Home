#pragma once

int TaskNumb();
int SizeOfArr();
void PrintMatrix(int * arr, int * column, int *row);
int CreateMatrix(int *arr, int *column, int *row);
void SizeOfMatrix(int * column, int * row);
void MaxNumbInRow(int *arr, int * column, int * numb, int * max);
void MaxNumbInColumn(int * arr, int * row, int * numb, int * max);
void MaxNumb(int *arr, int * column, int * row, int * arrRow, int * arrCol);
int ArrManualFilling(int * arr, int * length);
void NumbCopy(int * from, int * to, int * length);
//int SumOfElements(int * arr, int *length, OddOrEven n);
int SumOfElements(int * arr, int *length);
void ArrAutoFilling(int * arr, int *length);
bool DoWeHaveThisNumber(int * arr, int * length, int numb);
void PrintArr(int * arr, int * length);
int ArrManualFilling2(int * arr, int * length);