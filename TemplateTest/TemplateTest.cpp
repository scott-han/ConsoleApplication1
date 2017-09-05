// TemplateTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<Class T>
void f(vector<T>) {

}
struct C{
public:
	static void *operator new(std::size_t) = delete;
	static void *operator new[](std::size_t) = delete;
	
};

int main()
{
	C* c= new C();
	C* c = new C[3]);
    return 0;
}

