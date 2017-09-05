// dynamic_loops_num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> prime_set;

int max_prime = 1;//ensure 0,1 is not prime
bool isPrime(int n) {
	if (n <= max_prime)
	{
		if (prime_set.find(n) != prime_set.end())
			return true;
		else
			return false;
	}
	
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return false;
	}
	max_prime = n;
	prime_set.insert(n);
	return true;
	
}
void findPrimeFacotr(int n) {
	for (int i = 2; i <= n;++i ) {
		if (n % i == 0) {
		//	if (isPrime(i)) {
				cout << i << " ";
				n = n / i;
				i = 1;
		//	}
		}
	}
	cout <<"\n";
}
void f(int n, int depth) {
	
	vector<int> v(depth, 0);
	
	while (true) {
		if (v[0] < n)
		{
			for (auto e : v)
				cout << e;
			cout << "\n";
			++v[0];
		}
		else {
			v[0] = 0;
			int depth_idx = 1;
			if (depth_idx == depth)
				return;
			while (true) {
				if (v[depth_idx] < n - 1) {
					++v[depth_idx];
					break;
				}
				else {
					// v[depth_idx] == n - 1
					v[depth_idx++] = 0;
				}
				if (depth_idx == depth) {
					return;
				}
			}
		}
	}
}
void calcu100() {
	int sum = 0;
	int max = 100;
	int st = 1;
	int delta = 3;
	while (st <= 100) {
		sum += st;
		st += delta;
		delta += 2;
	}
	cout << sum << "\n";
}
int main()
{
	calcu100();
	findPrimeFacotr(24);
	f(4, 3);
    return 0;
}

