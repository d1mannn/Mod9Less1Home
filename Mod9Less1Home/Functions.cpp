#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "Header.h"

typedef enum OddOrEven 
{
	odd, even
};

int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите номер задания - ");
	int task;
	scanf_s("%d", &task);
	return task;
}

int SizeOfArr()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите размерность массива - ");
	int size;
	scanf_s("%d", &size);
	return size;
}

void SizeOfMatrix(int * column, int * row)
{
	setlocale(LC_ALL, "Rus");
	printf("Введите количество столбцов - ");
	scanf_s("%d", column);
	printf("Введите количество строк - ");
	scanf_s("%d", row);
}


int CreateMatrix(int *arr, int *column, int *row)
{
	srand(time(NULL));
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			*(arr + i * *column + j) = -30 + rand() % 100;
		}
	}
	return *arr;
}

void PrintMatrix(int * arr, int * column, int *row)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			printf("%d\t", *(arr + i * *column + j));
		}
		printf("\n");
	}
}


void MaxNumbInRow(int *arr, int * column, int * numb, int * max)
{	
	//*max = *(arr + *numb * *column + 0);
	for (int i = *numb - 1; i < *numb; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			if (*(arr + i * *column + j) > *max)
				*max = *(arr + i * *column + j);
		}
	}
}

void MaxNumbInColumn(int * arr, int * row, int * numb, int * max)
{	
	//*max = *(arr + 0 * *numb + 0);
	for (int i = 0; i < *row; i++)
	{
		for (int j = *numb - 1; j < *numb; j++)
		{
			if (*(arr + i * *row + j) > *max)
				*max = *(arr + i * *row + j);
		}
	}
}

void MaxNumb(int *arr, int * column, int * row, int * arrRow, int * arrCol)
{	
	printf("\n-----\n");
	int count = 0;
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
		{	
			
			if (*(arr + i * *column + j) % 2 == 0)
			{
				arrRow[count] = *(arr + i * *column + j);
				printf("%d\n", arrRow[count]);
				count++;
				j = *column;
			} 
			if (j == *column - 1)
			{
				arrRow[count] = 0;
				printf("%d\n", arrRow[count]);
				count++;
				
			}
		}
	}
	printf("\n-----\n");
	count = 0;
	for (int i = 0; i < *row; i++)
	{
		for (int j = *column - 1; j >= 0; j--)
		{	
			if (*(arr + i * *column + j) % 2 == 0)
			{
				arrCol[count] = *(arr + i * *column + j);
				printf("%d\n", arrCol[count]);
				count++;
				j = -1;
			}
			if (j == 0)
			{
				arrCol[count] = 0;
				printf("%d\n", arrCol[count]);
				count++;

			}

		}
	}
}

int ArrManualFilling(int * arr, int * length)
{	
	setlocale(LC_ALL, "Rus");
	int count = 0;
	char answer[1];
	for (int i = 0; i < 50; i++)
	{	
		*length = *length + 1;
		printf("Введите число - ");
		scanf_s("%d", &arr[i]);
		count++;
		if (count == 5)
		{
			printf("Вы ввели 5 цифр.\nХотите выйти? y or n - ");
			scanf_s("%c", &answer[0]);
			scanf_s("%c", &answer[0]);
			if (answer[0] == 'y')
				return 0;
			count = 0;
		}
		
	}
}

int ArrManualFilling2(int * arr, int * length)
{
	setlocale(LC_ALL, "Rus");
	int count = 0;
	char answer[1];
	for (int i = 0; i < 50; i++)
	{
		printf("Введите число - ");
		scanf_s("%d", &arr[i]);
		count++;
		if (count == 5)
		{
			printf("Вы ввели 5 цифр.\nХотите выйти? y or n - ");
			scanf_s("%c", &answer[0]);
			scanf_s("%c", &answer[0]);
			if (answer[0] == 'y')
				return 0;
			count = 0;
		}

	}
}


void NumbCopy(int * from, int * to, int * length)
{
	for (int i = 0; i < *length; i++)
	{
		to[i] = from[i];
	}
}

//int SumOfElements(int * arr, int *length, OddOrEven n)
//{	
//	int sum = 0;
//	switch (n)
//	{
//	case odd:
//	{
//		for (int i = 0; i < *length; i++)
//		{
//			if (arr[i] % 2 != 0)
//				sum += arr[i];
//		}
//		return sum;
//	}
//		break;
//	case even:
//	{
//		for (int i = 0; i < *length; i++)
//		{
//			if (arr[i] % 2 == 0)
//			sum += arr[i];
//		}
//		return sum;
//	}
//		break;
//	default:
//		break;
//	}
//}

int SumOfElements(int * arr, int *length)
{
	int sum = 0;
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] % 2 == 0)
			sum += arr[i];
	}
	return sum;
}

void ArrAutoFilling(int * arr, int *length)
{
	srand(time(NULL));
	for (int i = 0; i < *length; i++)
	{
		arr[i] = -100 + rand() % 200;
	}
}

bool DoWeHaveThisNumber(int * arr, int * length, int numb)
{
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] == 20)
			return 1;
	}
	return 0;
}

void PrintArr(int * arr, int * length)
{
	for (int i = 0; i < *length; i++)
	{
		printf("%d\n", arr[i]);
	}
}