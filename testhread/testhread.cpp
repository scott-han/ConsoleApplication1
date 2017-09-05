// testhread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>       // std::cout
#include <thread>         // std::thread
using namespace std;
void foo()
{
	std::cout << "foo thread:" << this_thread::get_id() << "\n";
}

void bar(int x)
{
	std::cout << "bar thread:" << this_thread::get_id() << "\n"; 
}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n";
	std::cout << "main thread:" << this_thread::get_id() << "\n";
	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	return 0;
}
