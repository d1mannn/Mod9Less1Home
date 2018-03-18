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

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{
			case 1:
			{
				/*1.	��� ��������� ������ ����� �����
					a.������������ ���������� ������, ������ ������� �������� ����� �����������
					�� ������ �������� ���������������� ������� ���������� �������
					b.������������ ���������� ������, ������ ������� �������� ����� ����������� 
					�� ������ �������� ��������������� ������ ���������� �������*/
				int * matrix, column, row, numb, maxInRow = 0, maxInCol = 0;
				int * ArrRow, *ArrCol;
				SizeOfMatrix(&column, &row);
				ArrRow = (int*)calloc(row, sizeof(int));
				ArrCol = (int*)calloc(column, sizeof(int));
				matrix = (int*)calloc((column * row), sizeof(int));
				CreateMatrix(matrix, &column, &row);
				PrintMatrix(matrix, &column, &row);
				printf("\n������� ����� ������� �� 1 �� %d\n", column);
				do
				{
					scanf_s("%d", &numb);
				} while (numb < 1 || numb > column);
				MaxNumbInColumn(matrix, &row, &numb, &maxInCol);
				
				numb = 0;
				printf("\n������� ����� ������ �� 1 �� %d\n", row);
				do
				{
					scanf_s("%d", &numb);
				} while (numb < 1 || numb > row);
				MaxNumbInRow(matrix, &column, &numb, &maxInRow);
				printf("\n���� ����� � ������� - %d\n���� ����� � ������ - %d\n", maxInCol, maxInRow);
			} break;

			case 2:
			{
				/*2.	��� ��������� ������ ����� �����
					a.������������ ���������� ������, ������ ������� �������� ����� 
					������� ������� �������� ���������������� ������� ���������� �������
					(���� ������ �������� � ������� ���, �� �� ����� ����).
					b.������������ ���������� ������, ������ ������� �������� ����� 
					���������� ��������� �������� ��������������� ������ ���������� �������
					(���� ������ �������� � ������ ���, �� �� ����� ����).*/
				int * matrix, column, row;
				int * ArrRow, *ArrCol;
				SizeOfMatrix(&column, &row);
				ArrRow = (int*)calloc(row, sizeof(int));
				ArrCol = (int*)calloc(column, sizeof(int));
				matrix = (int*)calloc((column * row), sizeof(int));
				CreateMatrix(matrix, &column, &row);
				PrintMatrix(matrix, &column, &row);
				MaxNumb(matrix, &column, &row, ArrRow, ArrCol);

			} break;

			case 3:
			{
				/*3.	��� ��������� ������.
					a.������������ ���������� ������, ������ ������� �������� ����� 
					���������� ��������� ���������������� ������� ���������� �������, ������� ������� �����
					b.������������ ���������� ������, ������ ������� �������� ����� 
					����� ��������� ��������������� ������ ���������� �������, ������� ������� �����.*/
			} break;

			case 5:
			{
				//5.	������ ����� �����.������� �� ��� ������.��������� ����� ������ ��������� �������
				int arr[50], length = 0;
				ArrManualFilling(arr, &length);
				int *newArr;
				newArr = (int*)calloc(length, sizeof(int));
				NumbCopy(arr, newArr, &length);
				int sum = SumOfElements(newArr, &length);
				printf("����� ������ ��������� ����� = %d\n", sum);
				
			} break;

			case 6:
			{
				//6.	������ ����� ����� N � ������ �� N ������������ �����.���������� ���������� ������������� ��������� �������
				int arr[50], length = 0, sum = 0;
				ArrManualFilling(arr, &length);
				int *newArr;
				newArr = (int*)calloc(length, sizeof(int));
				NumbCopy(arr, newArr, &length);
				for (int i = 0; i < length; i++)
				{
					if (newArr[i] < 0)
					{
						printf("%d\n", newArr[i]); 
						sum++;
					}
						
				}
				printf("\n���������� ������������� = %d\n", sum);
			} break;

			case 10:
			{
				//10.	������ ������������ �����.������� �� ��� ������.���������� ������� �������������� ��������� �������.
				int length = SizeOfArr();
				int * arr, sum = 0;
				arr = (int*)calloc(length, sizeof(int));
				ArrManualFilling2(arr, &length);
				for (int i = 0; i < length; i++)
				{
					sum += arr[i];
				}
				printf("������� �������������� - %d\n", sum / length);
			} break;
			/*
				4.	��� ��������� ������ �������� N x M, ����������� ������ �������
				a.��� ��� ��������, ������� ����, �������� � ���������� ������.
				b.��� ��� ������������� �������� �������� � ���� ���������� ������, � ��������� � � ������
				
				7.	������ ����� ����� N.������� ������ �� N ������������ �����.��������� ������������ ���������, ������ ������� ������ 7.
				8.	������ ������������ �����.������� �� ��� ������ ���������� ���������� ������� �������
				9.	������ ����� ����� N � ������ �� N ����� �����.���������� ���������� ������� �������
				
				11.	������ ������������ �����.������� �� ��� ������.���������� ���������� ��������������� ��������� �������
				12.	������ ����� ����� N � ������ �� N ������������ �����.���������� ������ ���������� �������������� �������� �������
				13.	������ ����� ����� N.������� ������ �� N ������������ �����.��������� ����� ������������ � ������������� ���������.
				14.	������ ������������ �����.������� �� ��� ������.��������� ������������ ������������ � ������������� ���������.
				*/
			case 15:
			{	
				//15.	������ ����� ����� N � ������ �� N ����� �����.����������, ���� �� � ������� ����� 20.
				int length = SizeOfArr();
				int * arr;
				arr = (int*)calloc(length, sizeof(int));
				ArrAutoFilling(arr, &length);
				PrintArr(arr, &length);
				int result = DoWeHaveThisNumber(arr, &length, 20);
				if (result == 1)
					printf("��, ���� ����� 20\n");
				else
					printf("���, ����� 20 ���\n");
			} break;
		}
	} while (task > 0);
}