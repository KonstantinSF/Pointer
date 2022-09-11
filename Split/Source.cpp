#include<iostream>
using namespace std; 

void FillRand (int arr[], const int n);
void Print(int arr[], const int n);
void Print (int*arr[], int n);

void main()
{
	setlocale(LC_ALL, ""); 
	const int n = 10;
	int e=0; //���������� ��������� ������� ������� even[]
	int arr[n] = {}; 
	FillRand(arr, n); 
	Print(arr, n); 

	for (int i = 0; i < n; i++)//�������� ���-�� ������ ��-�� �������
	{
		if (arr[i] % 2 == 0)
		{
			e++;
		}
	}
	int o = n-e; //���������� ��������� ��������� ������� odd[]
	int* even=new int[e];//������ ������
	int* odd = new int[o]; //������ ��������
	int countNum=0;//������� �������� ��������� ������� 
	for (int i=0; i<e; i++)//���������� ������ ���� �����
	{
		for (int k = countNum; k < n; k++)//���������� ��� ������, ������� �� ����. �� ��������� ����������� ���������;
		{
			if (arr[k] % 2 == 0)//���� ������
			{
				even[i] = arr[k]; //��������� ��� ������
				countNum = k + 1; //������ �������, ����� ������ �������� �� ���� ��������;
				break;//���������, ���� �������� �������� � ������ ������
			}
		}
	}
	Print(even, e);//����� �� ����� ������� �������
	countNum = 0;//�������� ������� �������� ��� �������
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
	Print(odd, o);//����� �� ����� ��������� �������
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