// WorkThread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <thread>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <shared_mutex>
using namespace std;


mutex outLock;
shared_mutex workerAccess;
bool shouldIWork = true;

class WorkerKiller
{
public:

	void operator()()
	{
		lock_guard<shared_mutex> lock(workerAccess);

		cout << "Grabbed exclusive lock, killing system" << endl;
		this_thread::sleep_for(chrono::seconds(5));
		shouldIWork = false;
		cout << "KILLING ALL WORK" << endl;
	}

private:
};

class Worker
{
public:
	int j;
	Worker(int i): j(i)
	{
	}

	void operator()()
	{
		shared_lock<shared_mutex> lock(workerAccess);
		
		cout <<j<< " Worked 1234567890 her work\n" << endl;
		
		if (!shouldIWork) {
			
			lock_guard<mutex> _(outLock);
			
			cout << j<< " Workers are on strike.  This worker refuses to work" << endl;
		}
		else {
			

			lock_guard<mutex> _(outLock);
			this_thread::sleep_for(chrono::seconds(3));
			cout <<j<< " Worked finished her work" << endl;
		}
	}
};

int main()
{
	Worker w1(1);
	Worker w2(2);
	Worker w3(3);
	Worker w4(4);
	Worker w5(5);
	Worker w6(6);
	Worker w7(7);
	Worker w8(8);
	WorkerKiller wk;

	thread workerThread1(w1);
	thread workerThread2(w2);
	thread workerThread5(w5);
	thread workerThread6(w6);
	thread workerThread7(w7);
	thread workerThread8(w8);
	
	
	thread workerKillerThread(wk);

	thread workerThread3(w3);
	thread workerThread4(w4);

	workerThread1.join();
	workerThread2.join();
	workerThread5.join();
	workerThread7.join();
	workerThread8.join();
	workerThread6.join();

	workerKillerThread.join();
	workerThread3.join();
	workerThread4.join();

	return 0;
}
