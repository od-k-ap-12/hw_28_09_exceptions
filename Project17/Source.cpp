#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
	MyArray<int> arr(10);
	arr.Show();
	cout<<arr.GetUpperBound();
	cout << endl;
	cout<<arr.GetSize();
	cout << endl;
	arr.Add(5);
	arr.Show();
	MyArray<int> arr1(5);
	arr = arr1;
	cout << endl;
	arr.Show();
	arr.SetSize(10);
	cout << endl;
	arr.Show();
	arr.SetAt(3, 6);
	arr.SetAt(4, 8);
	arr.SetAt(5, 2);
	cout << endl;
	arr.Show();
	arr.InsertAt(4, 4);
	arr.RemoveAt(5);
	cout << endl;
	arr.Show();
	cout<<arr.GetData();
	cout << endl << endl;
	system("pause");
}