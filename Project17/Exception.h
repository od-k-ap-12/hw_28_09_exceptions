#pragma once
#include<iostream>
using namespace std;

class Base
{
protected:
	char str[100];
public:
	Base()=default;
	Base(const char* s)
	{
		strcpy_s(str, strlen(s) + 1, s);
	}
	virtual void Print()
	{
		cout << str << endl;
	}

};
class InvalidIndex : public Base
{
public:
	InvalidIndex() {}
	InvalidIndex(const char* s) :Base(s)
	{}
	void Print()
	{
		cout << "Invalid index\n";
		cout << str << endl;
	}
};
class InvalidArraySize : public Base
{
public:
	InvalidArraySize() { }
	InvalidArraySize(const char* s) :Base(s)
	{}
	void Print()
	{
		cout << "Invalid array size\n";
		cout << str << endl;
	}
};

