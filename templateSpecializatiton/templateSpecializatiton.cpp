// templateSpecializatiton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
template <typename A, size_t B>
class Example {
public:
	Example()
	{
		Construct<B>(identity<A, B>());
	}

	A foo()
	{
		return foo<B>(identity<A, B>());
	}

private:
	template <typename A, size_t B>
	struct identity {};

	template <size_t B>
	void Construct(identity<A, B> id)
	{
		for (size_t i = 0; i < B; ++i)
		{
			value[i] = i;
		}
		std::cout << "default constructor\n";
	}

	template <size_t B>
	void Construct(identity<A, 2> id)
	{
		value[0] = 0;
		value[1] = 0;
		std::cout << "special constructor\n";
	}

	template <size_t B>
	A foo(identity<A, B> id)
	{
		A r = 0;
		for (size_t i = 0; i < B; ++i)
		{
			r += value[i];
		}
		std::cout << "default foo\n";
		return r;
	}

	template <size_t B>
	A foo(identity<A, 2> id)
	{
		std::cout << "special foo\n";
		return value[0] + value[1];
	}

	A value[B];
};
template <int n>
 constexpr int  Fac() {

	return  n * Fac<n - 1>();
}
  template <>
constexpr int  Fac<1>() {

	return 1;
}
template<bool> struct CompileTimeChecker
{
	CompileTimeChecker(...) {}
};
template<> struct CompileTimeChecker<false> { };
#define STATIC_CHECK(expr, msg) \
{\
class ERROR_##msg {}; \
 sizeof(CompileTimeChecker<(expr) != 0>((ERROR_##msg())));\
}
template <class To, class From>
To safe_reinterpret_cast(From from)
{
	STATIC_CHECK(sizeof(From) <= sizeof(To),
		Destination_Type_Too_Narrow);
	return reinterpret_cast<To>(from);
}
template <int v>
struct Int2Type
{
	static const int val = v;
};

class NullType {};
template <typename T>
class TypeTraits
{
private:
	template <class U> struct PointerTraits
	{
		enum { result = false };
		typedef NullType PointeeType;
	};
	template <class U> struct PointerTraits<U*>
	{
		enum { result = true };
		typedef U PointeeType;
	};
public:
	enum { isPointer = PointerTraits<T>::result };
	typedef typename PointerTraits<T>::PointeeType PointeeType;
};
void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}
int fib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
void fibonacci(int n) {
	
	if (n > 2){
		int t;
		cout << "0 1 ";
		for (int i = 3,  prev = 0,  prev2 = 1; i <= n; ++i) {
			t = prev + prev2;
			cout << t << " ";
			prev = prev2;
			prev2 = t;
		}
	}
}
int main()
{
	fibonacci(10);
	using namespace std::placeholders;  // for _1, _2, _3...

										// demonstrates argument reordering and pass-by-reference
	int n = 7;
	// (_1 and _2 are from std::placeholders, and represent future
	// arguments that will be passed to f1)
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001);
	Int2Type<2> s;
	auto vv = TypeTraits<vector<int>::iterator>::isPointer;
	int j1 = s.val;
	void* somePointer = &j1;
	double* c = safe_reinterpret_cast<double*>(somePointer);
	constexpr int j = Fac<5>();
	Example<int, 3> example; // change the 2 to see the difference
	int n1 = example.foo();
	std::cin.get();
	return 0;
}



