﻿#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Выделение памяти и инициализация 2д массива
int** Generate2DArray(int N, int M, int** from = nullptr, int ishift = 0, int jshift = 0)
{
	int** out = new int* [N];
	if (from != nullptr)
		for (int i = 0; i < N; i++)
		{
			out[i] = new int[M];
			for (int j = 0; j < M; j++)
				out[i][j] = from[i + ishift][j + jshift];
		}
	else
		for (int i = 0; i < N; i++)
		{
			out[i] = new int[M];
			for (int j = 0; j < M; j++)
				out[i][j] = 0;
		}
	return out;
}

//Заполнение 2д массива псевдослучайными числами или значениями с консоли
void Fill2DArray(int** array, int n, int m, bool fillType)
{
	if (fillType == 0)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> array[i][j];
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				array[i][j] = rand() % 10;
	}
				
}

//Вывод 2д массива
void Print2DArray(int** array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << array[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> n1 >> m1;
	} while (n1 <= 0 || m1 <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> n2 >> m2;
	} while (n2 <= 0 || m2 <= 0);

	int** M1 = Generate2DArray(n1, m1);
	int** M2 = Generate2DArray(n2, m2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"0 - Вручную \n1 - Случайным образом\n";
		cin >> k;
	} while (k < 0 || k > 1);

	Fill2DArray(M1, n1, m1, k);
	Fill2DArray(M2, n2, m2, k);
	Print2DArray(M1, n1, m1);
	Print2DArray(M2, n2, m2);

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	int shift = l / 2;
	int** M3 = Generate2DArray(l, l);
	int** M4 = Generate2DArray(l, l);

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
			M3[i][j] = M1[i][j];
		delete[] M1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
			M4[i][j] = M2[i][j];
		delete[] M2[i];
	}

	delete[] M1, M2;

	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	Print2DArray(M3, l, l);
	cout << "\nМатрица 2\n\n";
	Print2DArray(M4, l, l);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = Generate2DArray(l, l);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из промежуточных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			for (int z = 0; z < l / 2; z++)
			{
				M5[i][j] += (M3[i][z] + M3[i + shift][z + shift]) * (M4[z][j] + M4[z  +shift][j+ shift]) + M3[i + shift][z + shift] * (M4[z  +shift][j] - M4[z][j]) - (M3[i][z] + M3[i][z + shift]) * M4[z  +shift][j+ shift] + (M3[i][z + shift] - M3[i + shift][z + shift]) * (M4[z  +shift][j] + M4[z  +shift][j+ shift]);
				M5[i][j + l / 2] += M3[i][z] * (M4[z][j + shift] - M4[z  +shift][j+ shift]) + (M3[i][z] + M3[i][z + shift]) * M4[z  +shift][j+ shift];
				M5[i + l / 2][j] += (M3[i + shift][z] + M3[i + shift][z + shift]) * M4[z][j] + M3[i + shift][z + shift] * (M4[z  +shift][j] - M4[z][j]);
				M5[i + l / 2][j + l / 2] += (M3[i][z] + M3[i + shift][z + shift]) * (M4[z][j] + M4[z  +shift][j+ shift]) - (M3[i + shift][z] + M3[i + shift][z + shift]) * M4[z][j] + M3[i][z] * (M4[z][j + shift] - M4[z  +shift][j+ shift]) + (M3[i + shift][z] - M3[i][z]) * (M4[z][j] + M4[z][j + shift]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	cout << "\nРезультирующая матрица\n\n";
	Print2DArray(M5, n1, m2);
	system("pause");
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}

	delete[] M3, M4, M5;
	return 0;
}