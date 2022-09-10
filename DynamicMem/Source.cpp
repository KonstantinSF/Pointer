#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr, int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);

	delete[] arr;

	//Memory leaks
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//„ерез арифметику указателей и оператор разыменовани€
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int* arr, int& n, int value)
{
	//1) —оздаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2)  опируем содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ѕосле того как все данные скопированы из исходного массива в буферный,
	//	 исходный массив больше не нужен, и его можно удалить:
	delete[] arr;

	//4) ѕодмен€ем адрес исходного массива в указателе 'arr' адресом нового массива:
	arr = buffer;

	//5) » только после всего этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' по€вилс€ еще один элемент, 
	//в который можно сохранить значение.

	//6) ѕосле того как мы добавили в массив элемент, количество элементов массива увеличиваетс€ на 1
	n++;
	//7) Mission complete - Ёлемент добавлен!
	return arr;
}

/*
-------------------------------------------------
Debug Assertion Failed:
1. ”даление из статической пам€ти
2. ѕовторное удаление динамической пам€ти, а именно,
   когда оператору delete[] передали два раза один и тот же адрес.
-------------------------------------------------
*/