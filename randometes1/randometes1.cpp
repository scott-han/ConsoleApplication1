// randometes1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include<typeinfo>
using namespace std;

class base {
public:
	int a;
	base() :a(0)
	{}
	int getA() { return a; }
};
class der :public base
{
public:
	int b;
	der() :b(1)
	{}
	int getB() { return b; }
};
template<class T>
void display(T *obj, int ele)
{
	for (int i = 0; i < ele; i++)
	{
		cout << (obj + i)->getA() << endl;
	}
}

int main()
{
	//const_cast
	const int i = 3;
	base arrb[i];
	display(arrb, 3);
	der arrd[i];
	display(arrd, 3);
	return 0;
}
