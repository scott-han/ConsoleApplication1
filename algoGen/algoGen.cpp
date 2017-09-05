// algoGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int x, y;
	x = 10;
	y = 20;
	auto d1 = (x++)*3 + (x++)*2;
	auto d = x++ + ++y;
	auto t = y++ + ++x;
    return 0;
}

