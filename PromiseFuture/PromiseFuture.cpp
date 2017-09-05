// PromiseFuture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <future>
#include <iostream>
using namespace std;
int func1(std::future<int>& delayParam) {
	cout << "wait for result\n";
	int x = delayParam.get(); //line A
	//throw exception("some exception");
	//int y = 0;//func_threw();//line b
	cout << "go to sleep\n";
	this_thread::sleep_for(5s);
	cout << "wake up\n";
	return 10;//line c
}
void func2(std::promise<int> & result, std::promise<bool> &done) {
	result.set_value(10); //line d
	cout << "set value done\n";
	done.set_value(true); //line e
	cout << "go to sleep\n";
	this_thread::sleep_for(5s);
	cout << "wake up\n";
}
int main()
{
	promise<int> promisedArgument;
	future<int> futureArgument = promisedArgument.get_future();
	
	auto f = async(launch::async, func1, ref(futureArgument)); //line f
	this_thread::sleep_for(5s);
	cout << "wake up set reuslt\n";
	promisedArgument.set_value(4); //line g

	try {
		bool isValid = f.valid(); //line h
		int y1 = f.get();  //line i
		cout << y1 << "\n";
		//isValid = f.valid();//line j
		//int y2 = f.get(); //line k
	}
	catch (...) {
	auto dd =	current_exception();
	}

	promise<int> resultPromise;
	promise<bool> donePromise;

	future<int> resultFuture = resultPromise.get_future();
	future<bool> doneFuture = donePromise.get_future();

	async(launch::async, func2, ref(resultPromise), ref(donePromise));//line l
	bool done = doneFuture.get(); //line m
	int result_f2 = resultFuture.get(); //line n

    return 0;
}

