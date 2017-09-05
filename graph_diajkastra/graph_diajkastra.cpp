// graph_diajkastra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <numeric>
#include <memory>
#include <iostream>
using namespace std;
using Graph = vector< set<pair<int, int>>>;
void fs(string  s) { cout << "s called\n"; }//line 1 and line2 ae amgiguous
void fs(string && s) { cout << "fs r called\n"; }
void fs(const string & s) { cout << "fs l called\n"; }//line 1 and line2 ae amgiguous
void fs( char* && s) { cout << "fs char called\n"; }
//template<class T>
//void fs(T && s) { cout << "fs template called\n"; }
struct Pq_oder
{
	bool operator()(const pair<int, int> &left, const pair<int, int> &right) { return left.second > right.second; }
};
using Pq = priority_queue<pair<int, int>,vector<pair<int, int>>, Pq_oder>;
Pq pq;
const int MAX_NODE = 100;
Graph g(MAX_NODE);
const pair<int, int> DEFAULT(-1, numeric_limits<int>::max());
vector<pair<int,int> > dist_map(MAX_NODE, DEFAULT);
vector<bool> visited_map(MAX_NODE, false);
//class s1 { public: int i; s1() {} };
//void fs(s1 *p) {}
//class s2 : public s1 { public: int j; s2() {} };
//void f(const shared_ptr<s1> &p) { cout << &p; }
//void f2(shared_ptr<s2> p) { cout << &p; }
int diajkastr(int source, int target)
{
	/*auto pd = make_unique<s1>();
	fs(pd.get())*/;
	/*string ddsa{};
	fs(ddsa);
	fs("afdasd");*/
	/*f2(std::make_unique<s2>());
	s2 *ssa = new s2;
	s1 *p = dynamic_cast<s1*> (ssa);
	s2 sss{};
	auto ps = std::make_shared<s2>();
	auto ps2 = std::make_shared<s1>();
	cout << &ps;
	f(ps);
	std::shared_ptr<s1> base(new s1());
	std::shared_ptr<s2> derived = std::static_pointer_cast<s2>(base);
	std::shared_ptr<s2> derived = std::dynamic_pointer_cast<s2>(base);
	f2(derived);
	shared_ptr<s1> ss =ps;*/
	
		dist_map[source] = make_pair(0, 0);
		auto s = source;
		while (true){
			for (auto& d : g[s])
			{
				
				if (!visited_map[d.first])
				{
					auto dist = dist_map[s].second + d.second;
					if (dist < dist_map[d.first].second)
					{
						dist_map[d.first].second = dist;
						dist_map[d.first].first = s;
					}
					
					pq.push(make_pair(d.first, dist));
				}
			}
			visited_map[s] = true;
			if (s == target)
				return dist_map[target].second;
			
			while ( !pq.empty() && visited_map[ pq.top().first])
				pq.pop();
			if (pq.empty())
				return -1;
			else
			{
				s = pq.top().first;
				pq.pop();
			}
		}
	
}
int main()
{
	Graph::value_type t{ {2,1},{3,9},{6,10} };
	g[1].swap(t);
	

	g[2].emplace(make_pair(1, 1));
	g[2].emplace(make_pair(4, 1));
	g[2].emplace(make_pair(3, 6));

	g[3].emplace(make_pair(2, 6));
	g[3].emplace(make_pair(1, 9));
	g[3].emplace(make_pair(4, 1));
	g[3].emplace(make_pair(6, 2));

	g[4].emplace(make_pair(3, 1));
	
	g[5].emplace(make_pair(6, 9));

	g[6].emplace(make_pair(1, 10));
	g[6].emplace(make_pair(3, 2));
	g[6].emplace(make_pair(5, 9));

	auto re = diajkastr(1, 5);
    return 0;
}

