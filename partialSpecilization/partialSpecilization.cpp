// partialSpecilization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
template <typename T, int nValue> class Object {
private:
	T m_t;
	Object();
public:
	Object(T t) : m_t(t) {}
	T Get() { return m_t; }
	Object& Deform() {
		m_t *= nValue;
		return *this;
	}
};

template <typename T>
class Object<T, 0>
{
private:
	T m_t;
	Object();
public:
	Object(T t) : m_t(t) {}
	
	T Get() { return m_t; }
	Object& Deform()
	{
		std::cout << "Spec\n";
		m_t = -1;
		return *this;
	}
};

int main() {
	Object<int, 7> nObj(1);
	nObj.Deform();
//	Object<int, 0> nObj2(2,3);
//	nObj2.Deform();
	std::cout << nObj.Get();
}



