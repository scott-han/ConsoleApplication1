// threadtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
#include <future>
using namespace std;
void f(int& i)
{
	cout << "thread " << i << endl;
}
void f1()
{
	cout << "start " <<  endl;
	this_thread::sleep_for(chrono::seconds(5));
	cout << "end" << endl;
}
struct s
{
	s(s&& s) {
		cout << "move" << endl;
	}
	s& operator=(s&& ts) { 
		cout << "move a" << endl; return *this; }
	s(const s& ts) = default;
	s() = default;
};
struct copm
{
	s t1;
};
void f3(s&& d)
{
	vector<s> v;
	v.push_back(move(d));
}

int main()
{


	vector<copm> dd;
	dd.push_back(copm());
	//f3(s());
	vector<thread> ws;
	for (int i=0; i < 20; ++i)
	{
		
		auto t = thread(&f, ref(i));//has to use ref, 
		ws.push_back(move(t));
	}
	for (int i = 40; i < 50; ++i)
	{

		cout << "adfas"<<endl;
	}
	cout << "from main" << endl;
	for_each(ws.begin(), ws.end(), [](thread &t){
		t.join();
	});
	auto fu = async( f1);
	//fu.get();
	char name[256];
	std::cin.getline(name,256);
		std::string name1;

		std::cout << "Please, enter your full name: ";
		std::getline(std::cin, name1);
		//
		std::cout << "Hello, " << name << "!\n";
    return 0;
}

