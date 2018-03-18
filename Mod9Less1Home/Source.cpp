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
				/*1.	Дан двумерный массив целых чисел
					a.Сформировать одномерный массив, каждый элемент которого равен наибольшему
					по модулю элементу соответствующего столбца двумерного массива
					b.Сформировать одномерный массив, каждый элемент которого равен наибольшему 
					по модулю элементу соответствующей строки двумерного массива*/
				int * matrix, column, row, numb, maxInRow = 0, maxInCol = 0;
				int * ArrRow, *ArrCol;
				SizeOfMatrix(&column, &row);
				ArrRow = (int*)calloc(row, sizeof(int));
				ArrCol = (int*)calloc(column, sizeof(int));
				matrix = (int*)calloc((column * row), sizeof(int));
				CreateMatrix(matrix, &column, &row);
				PrintMatrix(matrix, &column, &row);
				printf("\nВведите номер столбца от 1 до %d\n", column);
				do
				{
					scanf_s("%d", &numb);
				} while (numb < 1 || numb > column);
				MaxNumbInColumn(matrix, &row, &numb, &maxInCol);
				
				numb = 0;
				printf("\nВведите номер строки от 1 до %d\n", row);
				do
				{
					scanf_s("%d", &numb);
				} while (numb < 1 || numb > row);
				MaxNumbInRow(matrix, &column, &numb, &maxInRow);
				printf("\nМакс число в столбце - %d\nМакс число в строке - %d\n", maxInCol, maxInRow);
			} break;

			case 2:
			{
				/*2.	Дан двумерный массив целых чисел
					a.Сформировать одномерный массив, каждый элемент которого равен 
					первому четному элементу соответствующего столбца двумерного массива
					(если такого элемента в столбце нет, то он равен нулю).
					b.Сформировать одномерный массив, каждый элемент которого равен 
					последнему нечетному элементу соответствующей строки двумерного массива
					(если такого элемента в строке нет, то он равен нулю).*/
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
				/*3.	Дан двумерный массив.
					a.Сформировать одномерный массив, каждый элемент которого равен 
					количеству элементов соответствующего столбца двумерного массива, больших данного числа
					b.Сформировать одномерный массив, каждый элемент которого равен 
					сумме элементов соответствующей строки двумерного массива, меньших данного числа.*/
			} break;

			case 5:
			{
				//5.	Ввести целые числа.Создать из них массив.Вычислить сумму чётных элементов массива
				int arr[50], length = 0;
				ArrManualFilling(arr, &length);
				int *newArr;
				newArr = (int*)calloc(length, sizeof(int));
				NumbCopy(arr, newArr, &length);
				int sum = SumOfElements(newArr, &length);
				printf("Сумма четных элементов равна = %d\n", sum);
				
			} break;

			case 6:
			{
				//6.	Ввести целое число N и массив из N вещественных чисел.Определить количество отрицательных элементов массива
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
				printf("\nКоличество отрицательных = %d\n", sum);
			} break;

			case 10:
			{
				//10.	Ввести вещественные числа.Создать из них массив.Определить среднее арифметическое элементов массива.
				int length = SizeOfArr();
				int * arr, sum = 0;
				arr = (int*)calloc(length, sizeof(int));
				ArrManualFilling2(arr, &length);
				for (int i = 0; i < length; i++)
				{
					sum += arr[i];
				}
				printf("Среднее арифметическое - %d\n", sum / length);
			} break;
			/*
				4.	Дан двумерный массив размером N x M, заполненный целыми числами
				a.Все его элементы, кратные трем, записать в одномерный массив.
				b.Все его положительные элементы записать в один одномерный массив, а остальные — в другой
				
				7.	Ввести целое число N.Создать массив из N вещественных чисел.Вычислить произведение элементов, модуль которых меньше 7.
				8.	Ввести вещественные числа.Создать из них массив определить наибольший элемент массива
				9.	Ввести целое число N и массив из N целых чисел.Определить наименьший элемент массива
				
				11.	Ввести вещественные числа.Создать из них массив.Определить количество неотрицательных элементов массива
				12.	Ввести целое число N и массив из N вещественных чисел.Определить индекс последнего отрицательного элемента массива
				13.	Ввести целое число N.Создать массив из N вещественных чисел.Вычислить сумму минимального и максимального элементов.
				14.	Ввести вещественные числа.Создать из них массив.Вычислить произведение минимального и максимального элементов.
				*/
			case 15:
			{	
				//15.	Ввести целое число N и массив из N целых чисел.Определить, есть ли в массиве число 20.
				int length = SizeOfArr();
				int * arr;
				arr = (int*)calloc(length, sizeof(int));
				ArrAutoFilling(arr, &length);
				PrintArr(arr, &length);
				int result = DoWeHaveThisNumber(arr, &length, 20);
				if (result == 1)
					printf("Да, есть число 20\n");
				else
					printf("Нет, числа 20 нет\n");
			} break;
		}
	} while (task > 0);
}