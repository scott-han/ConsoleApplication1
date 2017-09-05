// fibnumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <iostream>
using namespace std;
map<int, int> fibmap;
int fibnumber(int n)
{
	int ret = 0;
	if (n == 1 || n== 2)
	{
		ret = 1;
	}else
	{
		int one_pre = n - 1;
		if (fibmap.find(one_pre) == fibmap.end())
			one_pre = fibnumber(one_pre);
		else
			one_pre = fibmap[one_pre];

		int two_pre = n - 2;
		if (fibmap.find(two_pre) == fibmap.end())
			two_pre = fibnumber(two_pre);
		else
			two_pre = fibmap[two_pre];
		ret = one_pre + two_pre;
	}
	if (fibmap.find(n) == fibmap.end())
		fibmap.emplace(pair<int,int>(n, ret));
	return ret;
}
int main()
{
	cout << fibnumber(12);
    return 0;
}

