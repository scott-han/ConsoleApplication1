// Find2robots.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
void findRoborts(const vector<pair<int,int>> &p, int n) {
	vector<int> v(n, -1);
	vector <int> grp;
	grp.reserve(n);
	
	for (auto& pa : p) {
		if (v[pa.first] != -1)
		{
			v[pa.second] = v[pa.first];
			++grp[v[pa.first]];
		}
		else if (v[pa.second] != -1){
			v[pa.first] = v[pa.second];
			++grp[v[pa.second]];
		}
		else {
			grp.push_back(2);
			v[pa.first] = v[pa.second] = grp.size() - 1;
		}
	}
	int total = 0;
	int n_single_moedl_count = count_if(v.begin(), v.end(), [](int v) {return v == -1; });
	for (size_t gp_idx = 0; gp_idx < grp.size(); ++gp_idx) {
		for (size_t sub_idx = gp_idx + 1; sub_idx < grp.size(); ++sub_idx) {
			total += grp[gp_idx] * grp[sub_idx];
		}
		total += grp[gp_idx] * n_single_moedl_count;
	}
	total += n_single_moedl_count * (n_single_moedl_count - 1);
	cout << "total: " << total;
}
int main()
{
	int g = 2 % 5;
	vector<pair<int, int>> v{ {4,2},{0,1},{2,3} };
	findRoborts(v, 8);
    return 0;
}

