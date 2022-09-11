#include<iostream>
using namespace std; 

void FillRand (int arr[], const int n);
void Print(int arr[], const int n);
void Print (int*arr[], int n);

void main()
{
	setlocale(LC_ALL, ""); 
	const int n = 10;
	int e=0; //количество элементов четного массива even[]
	int arr[n] = {}; 
	FillRand(arr, n); 
	Print(arr, n); 

	for (int i = 0; i < n; i++)//опеделим кол-во четных эл-ов массива
	{
		if (arr[i] % 2 == 0)
		{
			e++;
		}
	}
	int o = n-e; //количество элементов нечетного массива odd[]
	int* even=new int[e];//массив четных
	int* odd = new int[o]; //массив нечетных
	int countNum=0;//счетчик итераций исходного массива 
	for (int i=0; i<e; i++)//перебираем массив четн чисел
	{
		for (int k = countNum; k < n; k++)//перебираем исх массив, начиная от след. за последним проверенным значением;
		{
			if (arr[k] % 2 == 0)//если четный
			{
				even[i] = arr[k]; //заполняем исх массив
				countNum = k + 1; //увелич счетчик, чтобы начать итерации со след значения;
				break;//прерываем, если записали значение в четный массив
			}
		}
	}
	Print(even, e);//вывод на экран четного массива
	countNum = 0;//обнулили счетчик итераций исх массива
	for (int i = 0; i < o; i++)
	{
		for (int k = countNum; k < n; k++)
		{
			if (arr[k] % 2 == 1)
			{
				odd[i] = arr[k];
				countNum = k + 1;
				break;
			}
		}
	}
	Print(odd, o);//вывод на экран нечетного массива
	delete[] even;
	delete[] odd;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
	*(arr + i) = rand() % 100; 
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
	cout << arr[i] << "\t"; 
	}
	cout << endl; 
}
void Print(int* arr[], int n)
{
	for (int i=0; i<n; i++) cout << arr[i] << "\t"; 
	cout << endl; 
}