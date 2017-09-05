// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread> 
#include <type_traits>
#include <vector>
using namespace std;
template<class T>
void s(T arg)
{
	typename std::remove_const<T>::type new_arg;
	if (std::is_const<decltype(new_arg)>::value)
	{
		cout << "isc_c\n";

	}
	else
	{
		cout << "is not\n";
	}
}
class de
{
public :
	int bu;
	static int st;
};
int de::st = 20;
class di
{
public :
	char bu;
	void f()const { std::cout << "dd"; };
	//void f() { std::cout << "dfnsadf"; };
};
class h :public de, public di {
	using di::bu;
public:int jd;
	   int ddd() { return de::bu; }
};
void fff() noexcept { throw 1; }
template <class T>
void fu(T t)
{
	static_assert(std::is_empty<T>::value, "emmpty");
}
class emptydd {};
void fun1(char c) {
	cout << c << std::endl;
}
void fun2(const int& c) {
	cout << c << std::endl;
}
void fun3( int& c) {
	cout << c << std::endl;
}
using namespace std;
enum e1 {a,b,c};
enum e2 { a1, b1, c1 };
int main()
{
	vector< pair<int, int>> f;
	const di dio;
	dio.f();
	int x = 5, y = 7;
	reference_wrapper<int> r = x;
	//reference_wrapper<int> r =
	thread(fun3, ref(x));
	thread(fun1, move('c'));
	thread(fun2, 5);
	//e1 d = a;
	//d = static_cast<e1>(10);
	//d += 1;//error
	//int ffd = d + 1;
	//e1 v = 1;//error
	//e2 d = a;//error
	int rows = 10;
	int col = 5;
	double **p = new double*[rows];
	for (int j = 0; j < col; ++j)
	{
		p[j] = new double[col];
	}
	//B::D *p = B::createD();
	//p->n = "asdf";
	int&& m{0};
	std::vector<int> d;
	fu(emptydd());
	/*h head;
	head.bu*/
	s("adfa");
	s(676);
	s(3.4);
	const h *ph = new h();
	h* dd = const_cast<h*>(ph);
	dd->jd = 5;
	h dd1;
	dd1.st;
    return 0;
}

