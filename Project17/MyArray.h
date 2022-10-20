#pragma once
#include<iostream>
#include "Exception.h"
using namespace std;

template<class T = int>
class MyArray
{
	T* arr;
	int size;
	int capacity;
	int grow;
public:
	MyArray(); 
	MyArray(int s); 
	void Show();
	MyArray(const MyArray& obj); 
	~MyArray(); 
	int GetSize(); 
	MyArray<T>& SetSize(int _size);
	bool IsEmpty(); 
	T& operator[] (int index); 
	int GetUpperBound(); 
	MyArray<T>& FreeExtra(); 
	void RemoveAll(); 
	T& GetAt(int index);
	MyArray<T>& SetAt(int index,T value);
	MyArray<T>& operator=(const MyArray<T>& obj);
	MyArray<T>& Add(T value);
	MyArray<T>& Append(MyArray<T>& obj);
	T** GetData();
	void InsertAt(int position, T value);
	void RemoveAt(int position);
};
template<class T>
T& MyArray<T>::operator[] (int index)
{
	return index >= 0 && index < size ? arr[index] : arr[0];
}

template<class T>
inline int MyArray<T>::GetUpperBound()
{
	return size - 1;
}

template<class T>
inline MyArray<T>& MyArray<T>::FreeExtra()
{
	if (arr != nullptr) {
		if (size == capacity) {
			return *this;
		}
		T temparr[size];
		for (int i = 0; i < size; i++)
		{
			temparr[i] = arr[i];
		}
		this->~MyArray();
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temparr[i];
		}
		return *this;
	}
}

template<class T>
inline void MyArray<T>::RemoveAll()
{
	this->~MyArray();
}

template<class T>
inline T& MyArray<T>::GetAt(int index)
{
	return arr[index];
}

template<class T>
inline MyArray<T>& MyArray<T>::SetAt(int index, T value)
{
	if (index >= capacity||index<0) {
		return *this;
	}
	else{
		arr[index-1] = value;
		return *this;
	}
}

template<class T>
MyArray<T>::MyArray()
{
	arr = nullptr;
	size = 0;
	capacity = 0;
	grow = 1;
}

template<class T>
MyArray<T>::MyArray(int s)
{
	try {
		if(s<1){
			throw new InvalidArraySize("Недопустимый размер массива");
		}
		size = s;
		capacity = s;
		arr = new T[size]{ 0 };
		grow = 1;
	}
	catch (Base* b)
	{
		b->Print();
	}
}

template<class T>
inline void MyArray<T>::Show()
{
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

template<class T>
MyArray<T>::MyArray(const MyArray& obj)
{
	size = obj.size;
	capacity = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	grow = obj.grow;
}
template<class T>
MyArray<T>::~MyArray()
{
	delete[]arr;
	size = 0;
	capacity = 0;
}
template<class T>
inline int MyArray<T>::GetSize()
{
	return size;
}
template<class T>
MyArray<T>& MyArray<T>::SetSize(int _size)
{
	if (_size > size) {
		T* temparr = new T[size]{0};
		for (int i = 0; i < size; i++)
		{
			temparr[i] = arr[i];
		}
		this->~MyArray();
		arr = new T[_size]{0};
		for (int i = 0; i < size; i++)
		{
			arr[i] = temparr[i];
		}
		size = _size;
		capacity = size;
		return *this;
	}
	else if (_size == size) {
		return *this;
	}
	else if (_size < size) {
		T* temparr=new T[size];
		for (int i = 0; i < size; i++)
		{
			temparr[i] = arr[i];
		}
		this->~MyArray();
		arr = new T[_size]{0};
		for (int i = 0; i < _size; i++)
		{
			arr[i] = temparr[i];
		}
		size = _size;
		capacity = size;
		return *this;
	}
}
template<class T>
inline bool MyArray<T>::IsEmpty()
{
	if (arr = nullptr) {
		return true;
	}
	if (arr != nullptr) {
		return false;
	}
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
	if (this == &obj) // a=a
	{
		return *this;
	}
	if (size != 0)
	{
		this->~MyArray();
	}
	size = obj.size;
	arr = new T[size]{0};
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

template<class T>
inline MyArray<T>& MyArray<T>::Add(T value)
{
	if (size == capacity) {
		T* temparr = new T[size]{0};
		for (int i = 0; i < size; i++)
		{
			temparr[i] = arr[i];
		}
		//this->~MyArray();
		arr = new T[size + grow]{0};
		for (int i = 0; i < size; i++)
		{
			arr[i] = temparr[i];
		}
		arr[GetUpperBound() + 1] = value;
		size += grow;
		capacity = size;
		return *this;
	}
	else {
		arr[GetUpperBound() + 1] = value;
	}
}

template<class T>
inline MyArray<T>& MyArray<T>::Append(MyArray<T>& obj)
{
	if (obj.size > capacity) {
		cout << "Error";
		return *this;
	}
	else {
		for (int i = 0; i < obj.size; i++)
		{
			arr[i] += obj.arr[i];
		}
		return *this;
	}
}

template<class T>
inline T** MyArray<T>::GetData()
{
	return &arr;
}

template<class T>
inline void MyArray<T>::InsertAt(int index, T value)
{
	try {
		if (index > size - 1 || index < 0) {
			throw new InvalidIndex("Выход за пределы массива");
		}
	}
	catch (Base* b)
	{
		b->Print();
	}
	T* temparr = new T[size + 1]{0};

	for (int i = 0; i < index; i++)
		temparr[i] = arr[i];
	temparr[index-1] = value;

	for (int i = index; i < size + 1; i++)
		temparr[i] = arr[i - 1];

	size++;

	delete[] arr;
	arr = temparr;
}

template<class T>
inline void MyArray<T>::RemoveAt(int index)
{
	try {
		if (index > size - 1 || index < 0) {
			throw new InvalidIndex("Выход за пределы массива");
		}
	}
	catch (Base* b)
	{
		b->Print();
	}
	if (index < 0 || index >= size)
	{
		return;
	}

	for (int i = index-1; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
}
