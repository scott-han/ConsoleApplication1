// kanpsack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using packs = vector<pair<int, int> >;

packs find( packs &p, int w)
{
	sort(p.begin(), p.end(), [](auto &left, auto &right) {return left.second < right.second; });
	return p;
}
int main()
{
	packs v = { {4,12,},{1,1},{10,4},{2,1},{2,2} };
	auto r = find(v, 15);
	for (auto& p : r)
	{
		cout << p.first << " " << p.second<< endl;
	}
    return 0;
}

