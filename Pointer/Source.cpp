#include <iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	int a = 2; 
	int* pa = &a;
	cout << a << endl;
	cout << pa << endl; 
	cout << *pa << endl; 
	cout << "------------------------" << endl; 
	const int n = 3;
	int arr[n] = { 10, 22, 13 }; 
	cout << arr << endl; 
	cout << *arr << endl; 
	for (int i = 0; i < n; i++)
	{
		cout << *(arr+i) << tab; 
	}
}