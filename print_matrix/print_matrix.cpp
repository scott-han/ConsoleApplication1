// print_matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <limits>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <string>
#include <cmath>
#include <sstream>
#include <stack>
#include <map>
#include <functional>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int mat[4][6] = { {1,2,3,4,5,6},
				  {7,8,9,10,11,12},
				  {13,14,15,16,17,18},
				  {19,20,21,22,23,24}  };
enum enum_mov_dir { hr, vd, hl, vu};

template<int row, int col>
void print(int(&mat)[row][col]) {
	int r = 0, c = 0;
	enum_mov_dir mov_dir = hr;
	int rc = col;
	int br = row;
	int tr = 0;
	int lc = -1;
	while (true) {
		std::cout << mat[r][c] << " ";
		switch (mov_dir)
		{
		case hr:
			if (c + 1 < rc ){
				++c;
			} else {
				--rc;
				mov_dir = vd;
				if (++r == br)
					return;
			}
			break;
		case vd:
			if (r + 1< br) {
				++r;
			}
			else {
				--br;
				mov_dir = hl;
				if (--c == lc)
					return;
			}
			break;
		case hl:
			if (c - 1 > lc) {
				--c;
			}
			else {
				++lc;
				mov_dir = vu;
				if (--r == tr) {
					return;
				}
			}
			break;
		case vu:
			if (r - 1 > tr) {
				--r;
			}
			else {
				++tr;
				mov_dir = hr;
				if (++c == rc) {
					return;
				}
			}
			break;
		default:
			break;
		}
	}
}
void big2(vector<int> &v) {
	sort(v.begin(), v.end());
	//set<int> s(v.begin(), v.end());
	int start = v[0];
	
	int big_s = start;
	int max_lenth = 0;
	int i = 1;
	auto s = v.size();
	bool is_continue = false;
	while (i < s) {
		if (v[i - 1] == v[i] - 1)
			is_continue = true;
		else {
			if (is_continue)
			{
				auto l = i- 1 - start;
				if (l > max_lenth) {
					max_lenth = l;
					big_s = start;
				}
			}
			start = i;
		}
		++i;
	}
	std::cout << v[big_s] << " " << v[big_s + max_lenth];
}
struct Node {
	int data;
	vector<Node*> neighbors;
};

Node* cloneNode(Node * n) {
	if (!n->neighbors.empty() 
		&& n == n->neighbors.back())
		return n->neighbors[n->neighbors.size() - 2];
	
	Node *new_node = new Node();
	new_node->data = n->data;
	n->neighbors.push_back(new_node);
	n->neighbors.push_back(n);
	int t = n->neighbors.size() - 2;
	for (int i = 0; i < t; ++i) {
		new_node->neighbors.push_back(cloneNode(n->neighbors[i]));
	}
	return new_node;
} 
void big1(vector<int> &v) {
	//sort(v.begin(), v.end());
	set<int> s(v.begin(), v.end());
	int start =*s.begin();
	int prev = start;
	auto b = ++s.begin();
	int big_s = start;
	int max_lenth = 0;
	while (b != s.end()) {
		if (prev == *b - 1)
			++prev;
		else {
			auto l = prev - start;
			if (l > max_lenth) {
				max_lenth = l;
				big_s = start;
			}
			start = prev = *b;
		}
		++b;
	}
	std::cout << big_s << " " << big_s+ max_lenth;
}

struct Node1{
	int i;
	Node1* next;
	Node1* random;
	Node1(int v) :i(v),next(nullptr), random(nullptr) {}
};
void printNode(Node1* root) {
	auto n = root;
	while (n) {
		std::cout << n->i << " next:" << (n->next ? n->next->i : 0) << " random " << (n->random ? n->random->i : 0) << "\n";
		n = n->next;
	}
	std::cout << "\n\n";
}
void CloneNode(Node1* root) {
	auto n = root;
	do {
		Node1 *new_node = new Node1(n->i);
		
		new_node->next = n->next;
		n->next = new_node;
		n = new_node->next;
	} while (n);
	printNode(root);
	n = root;
	do {
		if (n->random)
			n->next->random = n->random->next;
		n = n->next->next;
	} while (n);
	printNode(root);
	Node1 *clone_node_root = root->next;
	Node1 *o = root;
	n = clone_node_root;
	do {
		o->next = n->next;
		if (o->next)
			n->next = o->next->next;
		else
			n->next = nullptr;
		n = n->next;
		o = o->next;
	} while (n);
	printNode(root);
	printNode(clone_node_root);
	std::cout << "ds";
}
struct BTNode {
	int val;
	BTNode *left;
	BTNode *right;
};
void reverseBT(BTNode *btnode) {
	auto t = btnode->left;
	btnode->left = btnode->right;
	btnode->right = t;
	if (btnode->left)
		reverseBT(btnode->left);
	if (btnode->right) {
		reverseBT(btnode->right);
	}
	
}
void bfsPrint(BTNode *btnode) {
	queue<BTNode *> q;
	q.push(btnode);
	while (!q.empty()) {
		auto h = q.front();
		std::cout << h->val << " ";
		if (h->left)
			q.push(h->left);
		if (h->right)
			q.push(h->right);
		q.pop();
	}
	std::cout << "\n";
}

void findThreeNumber(vector<vector<int>> &v) {
	for (auto& a : v)
	{
		sort(a.begin(), a.end());
	}
	int min_distance = numeric_limits<int>::max();
	int res[3];
	auto s = min(min(v[0].front(), v[1].front()),min(v[1].front(), v[2].front()));
	auto l = max(max(v[0].back(), v[1].back()), max(v[1].back(), v[2].back()));
	int lb[3] = { 0,0,0 };
	for (int i = s; i <= l; ++i) {
		int i0 = v[0][lb[0]];
		int i1 = v[1][lb[1]];
		int i2 = v[2][lb[2]];
		
		
		set<int> s = { i0,i1,i2 };
		if (i0 == *s.begin() && lb[0] < v[0].size() - 1)
			++lb[0];
		if (i1 == *s.begin() && lb[1] < v[1].size() - 1)
			++lb[1];
		if (i2 == *s.begin() && lb[2] < v[2].size() - 1)
			++lb[2];
		if (lb[0] == v[0].size() - 1 ||
			lb[1] == v[1].size() - 1 ||
			lb[2] == v[2].size() - 1)
			break;
		auto dist = *s.rbegin() - *s.begin();
		if (dist == 0) {
			std::cout << "find value: " << i0 << " " << i1 << " " << i2;
			return;
		}
		if (dist < min_distance) {
			min_distance = dist;
			res[0] = i0;
			res[1] = i1;
			res[2] = i2;
		}
		++i;
	}
	std::cout << "find value: " << res[0] << " " << res[1] << " " << res[2];
}
int getgcd(int i, int j) {
	int gcd = 1;
	for (int k = 1; k <= i && k <= j; ++k) {
		if (i%k == 0 && j%k == 0) {
			i /= k;
			j /= k;
			gcd *= k;
		}
		else {
			++k;
		}
	}
	std::cout << "gcd: " << gcd << "\n";
	return gcd;
}
void calculateDifff(BTNode *btnode) {
	queue<BTNode *> q;
	q.push(btnode);
	int sum_o = 0;
	int sum_e = 0;
	bool is_o = true;
	int lev = 1;
	int current_lev_count = 1;
	int next_lev_count = 0;
	while (!q.empty()) {
		auto h = q.front();
		std::cout << h->val << " ";
		--current_lev_count;
		if (lev % 2) {
			sum_o += h->val;
		}
		else {
			sum_e += h->val;
		}
		if (h->left)
		{
			q.push(h->left);
			++next_lev_count;
		}
		if (h->right) {
			q.push(h->right);
			++next_lev_count;
		}
		q.pop();
		if (current_lev_count == 0) {
			current_lev_count = next_lev_count;
			next_lev_count = 0;
			++lev;
			std::cout << endl;
		}
	}
	std::cout << sum_o << "-" << sum_e << "\n";
}
class MrSw {
public:
	void write() {
		unique_lock<shared_mutex> u_loc(mut);
		++val;
	}
	int read() {
		shared_lock<shared_mutex> s_loc(mut);
		return val;
	}
private:
	int val = 0;
	shared_mutex mut;
};
string removep(string exp) {
	return "";
}
bool is_sum_found(vector<int> &vec, int k) {
	sort(vec.begin(), vec.end());
	int s = 0;
	int t = vec.size() - 1;
	
	while (true) {
		if ( s > t)
			return false;
		auto sum = vec[s] + vec[t];
		if (sum < k) {
			++s;
		}
		else if (sum > k) {
			--t;
		}
		else {
			return true;
		}
	}
	return false;
}

template <class T> 
class SizeOfT
{
	
public:	static auto getsize() {
	T val;
	//decltype(val) sd;

	return ((char*)(&val + 1) - (char*)(&val));
}
};
//template<typename T>
//int SizeOfT<T>::getsize() {
//	T val;
//	//decltype(val) sd;
//	
//	//return static_cast<int>(((char*)(&val + 1) - (char*)(&val)));
//}
class con {

public:
	con() { }
};
struct nodess
{
	
	int data;
	short i;
	char rest;
	short j;
};



int expect(vector<int> input, int x) {
	sort(input.begin(), input.end());
	map<int, vector<pair<int, int> >> ma;
	for (int i = 0; i < input.size(); ++i) {
		for (int j = 0; j < input.size(); ++i) {
			if (i != j) {
				int s = input[i] + input[j];
				if (ma.find(s) == ma.end()) {
					ma.insert(make_pair(s,vector<pair<int,int>>()));
				}
				ma[s].emplace_back(make_pair(i,j));
			}
		}
	}
	for (auto v : ma) {
		auto re = x - v.first;
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == re)
			for (auto ps : v.second)
			{
				if (ps.first != i & ps.second != i)
					return true;
			}
			
		}
	}
	return false;
}
void sortRGB(vector<char> &rgb) {
	int gh = -1;
	int bh = -1;
	if (rgb[0] == 'g') {
		gh = 0;
	}
	else if (rgb[0] == 'b') {
		bh = 0;
	}
	
	for (int i = 1; i < rgb.size(); ++i) {
		if (rgb[i] == rgb[i - 1])
		{
			continue;
		}
		if (rgb[i] == 'r') {
			if (gh != -1) {
				rgb[gh++] = 'r';
				if (bh != -1) {
					rgb[bh++] = 'g';
					rgb[i] = 'b';
				}
				else {
					rgb[i] = 'g';
				}
			}
			else if (bh !=-1) {
				rgb[bh++] = 'r';
				rgb[i] = 'b';
			}
		}
		else if (rgb[i] == 'g') {
			if (bh != -1) {
				rgb[bh++] = 'g';
				if (gh == -1)
					gh = bh -1;
				rgb[i] = 'b';
			}
			else if (gh == -1){
				gh = i;
			}
		}
		else if (bh == -1){
				bh = i;
		}
	}
}
bool findNum(vector<int> &s,int val) {

	int start_idx = 0;
	int end_idx = s.size();
	do{
		int mid = (start_idx + end_idx )/ 2;
		if (s[mid - 1] <= s[mid]) {
			if (val < s[mid] &&
				(binary_search(&s[0]+ start_idx, &s[0] + mid, val)))
					return true;
				start_idx = mid + 1;
			
		}
		else {
			if (val < s[mid] &&
				 (binary_search(&s[0]+ mid, &s[0] + end_idx, val, [](auto i1, auto i2) {return i1 > i2; })))
					return true;
				end_idx = mid - 1;
			
		}
	} while (start_idx < end_idx);
	return false;
}
static const int ARRAY_Q_SIZE = 8;
struct arrayQ {
	int q[ARRAY_Q_SIZE];
	int qh = -1;
	int qt = -1;
	int size = 0;
	void push(int val) {
		if (qh == -1) {
			qh = 0;
			qh = qt = 0;
			q[0] = val;
		}
		else if (qt == ARRAY_Q_SIZE- 1){
			if (qh > 0) {
				qt = 0;
				q[0] = val;
			}
			else {
				throw std::exception("q is full");
			}
		}
		else if (qt == qh) {
			++qt;
			q[qt] = val;
		}
		else if (qt < qh) {
			if (qt + 1 == qh) {
				throw std::exception("q is full");
			}else{
				++qt;
				q[qt] = val;
			}
		}
		else {
			++qt;
			q[qt] = val;
		}
	}
	int popQ() {
		int ret = 0;
		if (qh == -1) {
			throw std::exception("empty q");
		}
		else if (qh < qt) {
			ret = q[qh];
			q[qh++] = -1;
		}
		else if (qh == qt) {
			ret = q[qh];
			q[qh] = -1;
			qh = qt = -1;
		}
		else if (qh > qt) {
			if (qh == ARRAY_Q_SIZE - 1) {
				ret = q[qh];
				q[qh] = -1;
				qh = 0;
			}
			else {
				ret = q[qh];
				q[qh++] = -1;
			}
		}
		return ret;
	}
};
void printDbl(double d) {
	int i = d;
	int j = log(i) / log(2) + 1;
	int start = pow(2, j);
	char c[100] = {};
	int idx = 0;
	while (start) {
	   c[idx++] =start & i ? '1' : '0';
	   start >>= 1;
	}
}

int mingle(int a, int b)
{
	int c = b / 2;
	if (b <= 1) { return a; }

	cout << c << endl;
	return a*(b - 2 * c) + mingle(a, c);

}
char int2char(int num) {
	return static_cast < char> (65 + num);
}
std::string intTo26(int num)
{
	std::stringstream os;
	stack<char> s;
	while(true) {
		s.push(int2char(num % 26));
		num /= 26;
		if (num == 0)
			break;
		else
			--num;
	}
	while (!s.empty()) {
		os << s.top();
		s.pop();
	}
	return os.str();
}
struct sNode {
	sNode(int i) :data(i),next(nullptr) {}
	int data;
	sNode* next;
};
void printRever(sNode* n) {
	if (n->next) {
		printRever(n->next);
		cout << n->data;
		
	}else{
		cout << n->data;
	}
	
}
int calu(int val, int max_deom, vector<int> inp) {
	if (max_deom == 0) {
		if (val % inp[0] == 0)
			return 1;
		else
			return 0;
	}
	
	int rep = val / inp[max_deom];
	int ways = 0;
	for (int i = 0; i <= rep; ++i) {
		ways += calu(val - i*inp[max_deom], max_deom - 1, inp);
	}
	return ways;
}

int findSeqMath1(vector<int> &v) {
	unordered_map<int, vector<tuple<int,int>>> m;
	unordered_set<int> s;
	s.insert(v[0]);
	int longest = 1;
	for (int i = 1; i < v.size(); ++i) {
		for (auto j : s) {
			int d = v[i] - j;
			auto it = m.find(d);
			if (it == m.end()) {
				m.insert(make_pair(d, vector<tuple<int, int>>()));
				m[d].push_back(make_tuple(v[i], 2));
			}
			else {
				bool found = false;
				for (auto& t : it->second) {
					if (v[i] - get<0>(t) == d) {
						get<0>(t) = v[i];
						++get<1>(t);
						found = true;
						longest = max(longest, get<1>(t));
						std::cout << d << " at:" << get<0>(t) << " with " << get<1>(t) << "\n";
						break;
					}
				}
				if (!found) {
					it->second.push_back(make_tuple(v[i], 2));
				}
			}
		}
		s.insert(v[i]);
		
	}
	return longest;
}

int findSeqMath2(vector<int> &v) {
	int longest = 1;
	vector < unordered_map<int, int>> v1;
	v1.push_back(unordered_map<int, int>());
	for (int i = 1; i < v.size(); ++i) {
		int cv = v[i];
		v1.push_back(unordered_map<int, int>());
		for (int j = 0; j < i; ++j) {
			int step = cv - v[j];
			auto& dd = v1[i].find(step);
			if (dd == v1[i].end())
				v1[i].insert(make_pair(step, 2));
			auto& it = v1[j].find(step);
			if (it != v1[j].end()) {
				v1[i][step] = max(it->second + 1, v1[i][step]);
				longest = max(longest, v1[i][step]);
			}
		}
	}

	return longest;
}
struct Foo {
	int i{ 0 };
	Foo(Foo&& sf) {
		i = sf.i;
		sf.i = 0;
	}
	Foo() = default;
	Foo(const Foo& sf) = default;
	//	void f() const { cout << "const&\n"; }
	void f() const& { cout << "const&\n"; }
	void f() && { cout << "temp\n"; }
	int&& geti() {
		int i = 0;
		//return i; i is lvalue cannot bind to int&&
		return move(i);
	}
	
};
Foo f1() {
	Foo f;
	f.i = 3;
	return f;
}
void ffs(Foo&& s) {}
void test(int&& j) {}
struct Beta_ab {};
struct Beta {
	Beta_ab ab;
	Beta_ab const& getAB() const& { return ab; }
	Beta_ab && getAB() && { return move(ab); }
};
struct CAT
{
	CAT() {}
	CAT(const CAT&) { std::cout << "COPY"; }//if this is deleted it will not compile
	CAT(CAT&&) { std::cout << "MOVE"; }
	int f(int z)const { return z; }
	int j;
};
struct S2 {
	template<int N> static void A(int) {}
};
struct S3 {
	template<int N> struct A {};
};
int xx = 3;
template<class T>
void foo() {
	
T::A<0>(xx);
	//	T::template A<0>(xx);
}
template<class T>
struct rankq { static size_t const value = 0u; };
//partial specilization
template<class U, size_t N>
struct rankq<U[N]> {
	static size_t const value = 1u + rankq<U>::value;
};

//template<class T>
//struct remove_const {
//	using type_t = T;
//};
//template<class T>
//struct remove_const < T const>{
//	using type_t = T;
//};
//template <class T>
//struct Is_Type {
//
//};
template<bool bo>
struct bool_v_type {
	static  bool const value = bo;
};
using true_type_t = bool_v_type<true>;
using false_type_t = bool_v_type < false>;
template<class T, class ... Vari0>
struct Is_Same;

template<class T>
struct Is_Same<T> : false_type_t {};

template<class T,class ... Vari1>
struct Is_Same<T,T,Vari1...> : true_type_t {};

template<class T, class T1, class ... Vari1>
struct Is_Same<T, T1, Vari1...> : Is_Same<T, Vari1...> {};

struct mytd {
	mytd& operator=(mytd&& m) = delete;
	mytd& operator=(const mytd& m) {};
	typedef void td ;
};
template<class...>
using int_t = int;
template<class T,class U =int>
struct st : false_type_t {};
template<class T>
struct st<T,int_t<typename T::td>>: true_type_t {};


int main()
{
	auto ddsdf = st<mytd>::value;
	/*mytd ss;
	mytd ss1;
	ss = mytd();*/

	auto is_s = Is_Same<int, double, short,  bool>::value;
	int a1[3][4][5][6];
	auto sa = rankq<decltype(a1)>::value;
	foo<S2>();
	foo<S3>();
	using md = int(CAT::*);
	md dds= &CAT::j;
	
	using fp = int(CAT::*)(int) const;
	fp sfds = &CAT::f;
	const CAT cat;
	(cat.*sfds)(2);
	auto s_d = cat.*dds;
	CAT cat2 = std::move(cat);
	std::vector<int> vaaa = { 0, 1, 2, 3, 4, 5 };

	using RevIt = std::reverse_iterator<std::vector<int>::iterator>;
	RevIt r_end(vaaa.begin());
	RevIt r_begin(vaaa.end());
	auto ds = --r_end.base();
	
	std::cout << "\n";
	Beta asd;
	auto const &sd = asd.getAB();
	Foo fo;
	int sfsdf{};
	int&& j = 0;
	test(fo.geti());
	fo.i = 3;
	Foo&& fot = std::move(fo);
	Foo fora = std::move(fo);
	fot.i = 6;
	vector<int> vvs1 = { 1,6,3,5,9,7,-1,-4,0,-7,12,-10,-13,-13,-16,6,-19 };
	int rre = findSeqMath1(vvs1);
	vector<int> vss = { 5,10,20,50 };
	auto re = calu(25,3,vss);
	sNode* ss = new sNode(1);
	sNode* s1 = new sNode(2);
	ss->next = s1;

	sNode* s2 = new sNode(3);
	s1->next = s2;
	
	sNode* s3 = new sNode(4);
	s2->next = s3;
	printRever(ss);
	auto ret = intTo26(260);
	int i;
	for (i = 1; i <= 5; i++) {
		cout << mingle(i + 1, i - 1) << endl;
	}
	printDbl(10.897);
	arrayQ aq;
	aq.push(1);
	aq.push(2);
	aq.push(3);
	aq.push(4);
	aq.push(5);
	aq.push(6);
	aq.push(7);
	aq.push(8);
	
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.push(9);
	aq.push(10);
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.push(11);
	aq.push(12);
	aq.push(13);
	aq.push(14);
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	aq.popQ();
	//vector<char> rgb = { 'g','r','r','r','b','b', 'g','r','g','g','b','b','r','b','b' };
	//vector<char> rgb = { 'g','r','r','r','g','r','g','g','r' };
	//vector<char> rgb = { 'g','b','b', 'g','g','g','b','b','b','b' };
	//vector<char> rgb = { 'r','r','r','b','b', 'r','b','b','r','b','b' };
	vector<char> rgb = {'b', 'g','r','r','r','b','b', 'g','r','g','g','b','b','r','b','b' };

	/*std::vector<int> v12(12);
	std::generate(v12.begin(), v12.end(), std::rand);
	sort(v12.begin(), v12.end(), [](auto i1, auto i2) { return i1 < i2; });
	std::vector<int> v6(6);
	std::generate(v6.begin(), v6.end(), std::rand);
	sort(v6.begin(), v6.end(), [](auto i1, auto i2) { return i1 > i2; });
	v12.insert(v12.end(), v6.begin(), v6.end());*/
	std::vector<int> v12 = { 1,3,5,7,19,221,245,278,498,990,11200,45566,132,56,8,6,4,2,1,-3,-17 };
	findNum(v12, 8);
	sortRGB(rgb);
	auto s = sizeof(nodess);
	MrSw mr_sw;
	vector<thread> vt;
	mutex cout_mutex;
	std::cout << "main thread:" << this_thread::get_id() << "\n";
	/*int p[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<char> v11(sizeof(p), 0);
	
	memcpy(v11.data(), reinterpret_cast<char*> (&p[0]), sizeof(p));*/
	for (int tc = 0; tc < 8; ++tc) {
		vt.push_back(thread([&cout_mutex, &mr_sw, tc = tc]() {
			vector<int> res;
			for (int i = 1; i <= 50; ++i) {
				if (i % 3)
				{
					res.push_back(mr_sw.read());
					//this_thread::sleep_for(1s);
					/*{
						lock_guard<mutex> lo(cout_mutex);
						std::cout <<tc<< " after write:" << mr_sw.read() << "\n";
					}*/
				}
				else {
					mr_sw.write();
				}
				
			}
			
			lock_guard<mutex> lo(cout_mutex);
			{
				
				std::cout << tc  << ":" << this_thread::get_id()  << "\n";
				for (auto v : res) {
					std::cout << v << " ";
				}
				std::cout << "\n";
			}
		}));
	}
	for (auto& t : vt) {
		t.join();
	}
	auto btroot = new BTNode();
	btroot->val = 1;
	auto r2 = new BTNode();
	r2->val = 2;
	auto r3 = new BTNode();
	r3->val = 3;
	auto r4 = new BTNode();
	r4->val = 4;
	auto r5 = new BTNode();
	r5->val = 5;
	auto r6 = new BTNode();
	r6->val = 6;
	auto r7 = new BTNode();
	r7->val = 7;

	btroot->left = r2;
	btroot->right = r3;

	r2->left = r4;
	r2->right = r5;

	r3->left = r6;
	r3->right = r7;
	calculateDifff(btroot);

	getgcd(11, 24);
	vector<vector<int>> v1 = {
		{ 323,12,112,456,122,10 },
		{ 32,154,112,1566,11,233,189 },
		{ 43532,32,24,5,543,3244,10,14, }
	};
	findThreeNumber(v1);
	bfsPrint(btroot);
	reverseBT(btroot);
	bfsPrint(btroot);
	Node1* root = new Node1(1);
	Node1* n2 = new Node1(2);
	Node1* n3 = new Node1(3);
	Node1* n4 = new Node1(4);
	Node1* n5 = new Node1(5);
	Node1* n6 = new Node1(6);
	root->next = n2; root->random = n4;
	n2->next = n3; n2->random = n3;
	n3->next = n4; n3->random = n6;
	n4->next = n5; n5->random = root;
	n5->next = n6; n6->random = n2;
	printNode(root);
	CloneNode(root);
	vector<int> v{1,7,4,6,3,10,2,13,40,41,14,15,16,17,18};
	big2(v);
	print(mat);
    return 0;
}

