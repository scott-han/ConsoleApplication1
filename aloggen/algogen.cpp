#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <ctime> 
#include <functional>
#include <fstream>
#include <regex>
#include <map>
#include <thread>
using namespace std;

struct NodeS {
	NodeS(int dis,string v) :val(v), distance(dis) {}
	string val;
	int distance ;
};
struct Op {
	bool operator()(NodeS& n1, NodeS& n2) {
		return n1.distance < n2.distance;
	}
};
bool is_one(string s1, string s2) {
	if (s1.length() == s2.length()) {
		int n = 0;
		int j = 0;
		while (n < s1.length()) {
			if (s1[n] != s2[n])
				++j;
			if (j > 1)
				return false;
			++n;
		}
		if (j == 1)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

using Pq = priority_queue<NodeS, vector<NodeS>, Op>;
int findPath(set<string> &mp, string s, string d) {
	Pq pq;
	
	pq.push(NodeS(0,s));
	set<string> his;
	while (!pq.empty()){
		auto s = pq.top();
		pq.pop();
		if (is_one(d, s.val))
			return s.distance + 1;
		for (auto& e : mp) {
			
			if (his.find(e) == his.end() &&
				is_one(e, s.val)){
				
				if (e == d)
					return s.distance + 1;
				else{
					pq.push(NodeS(s.distance + 1, e));
					his.insert(e);
				}
				
			}
		}

	}
	return -1;
}


int convet(char c) {
	switch (c) {
	case '0':
			return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':

		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'a':

		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	}
}
void converttoDecimal(string hex) {
	int j=0;
	reverse(hex.begin(), hex.end());
	int i = 0;
	for (char c : hex) {
		j += convet(c)*pow(16, i++);
	}
	cout << hex << " to int: " << j;
}
struct seto {
	bool operator()(int a, int b) { return a > b; }
};
set<int,seto> s;
void f(int v, int k) {
	s.insert(v);
	if (s.size() > k) {
		s.erase(--s.end());
	}
}
void test1() {
	//
	  std::vector<int> v(1000);
	std::generate(v.begin(), v.end(), std::rand);
	for (int j : v) {
		f(j, 5);
	}
	sort(v.begin(), v.end(),greater<int>());
}

struct entry {
	string user;
	int bandwidth;
};
struct entryop {
	bool operator()(entry const& e1, entry const& e2) { return e1.bandwidth > e2.bandwidth; }
};
using m_type = map<string, map<string, int>>;
void readline(m_type& m, string const &s) {
	//string const& s = "User:B   Bandwidth: 60  CountryCode:USA";
	std::regex rgx(R"__(User:[\s]*(\w+)[\s]+Bandwidth:[\s]*(\d+)[\s]+CountryCode:[\s]*(\w+))__");


	std::smatch match;
	if (std::regex_search(s.begin(), s.end(), match, rgx))
	{
		string country = match[3];
		string user = match[1];
		std::string::size_type sz;   // alias of size_t
		
		int bandwidth = std::stoi(match[2], &sz);
		auto it = m.find(country);
		if (it == m.end()) {
			m.insert(make_pair(country, m_type::mapped_type()));
		}
		auto it2 = m[country].find(user);
		if (it2 == m[country].end()) {
			m[country].insert(make_pair(user, 0));
		}
		m[country][user] += bandwidth;
	}
}
void prossefile() {
	std::ifstream infile(R"(C:\Users\scott\Desktop\test.txt)");
	string line;
	m_type m;
	while (getline(infile, line)) {
		readline(m, line);
	}
	getline(cin, line);
}
int f11(int a, int b, int c) { return 1; }


template<class range, class Callable>
void trf_pr(const range& r, Callable c) {
	for (const auto& e : r) {
		cout << invoke(c, e) << "\n";
	}
}

int main() {
	vector<pair<int, int>> v{ {4,40},{5,50},{6,60} };
	trf_pr(v, [](const auto& p) {return p.first*p.second; });
	trf_pr(v, &pair<int, int>::second);
	int x = 10;
	int y = 20;
	x = x++ + ++ y;
	y = y++ + ++ x;
	thread t(&f11, 1, 3, 4);
	prossefile();
	test1();
	converttoDecimal("f1");
	set<string> dic = { "rat","pat", "dam" };
	int fe = findPath(dic, "sat", "pan");
}