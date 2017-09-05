// practice_random.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <list>
#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include<iterator>
#include <memory>
#include <queue>
#include <stack>
using namespace std;
const unordered_set<char> vowel{ 'a','A','e','E','i','I','o','O','u','U' };
int getValue(const string &input)
{
	int value = 0;
	for_each(input.begin(), input.end(), [&value](const char& ch)
	{
		vowel.find(ch) == vowel.end() ? value += 2 : ++value;
	});
	return value;
}
void printPatternq(int n)
{
	stack<string> sta;
	int current = 1;
	for (int i = 1; i <= n; ++i) {
		ostringstream os;
		os << current++;
		for (int j = 1; j < i; ++j) {
			os << "*" << current++;
		}
		os << "\n";
		//auto st = os.str();
		std::cout << os.str();
		sta.push(os.str());

	}

	while (!sta.empty()) {
		std::cout << sta.top();
		sta.pop();
	}
}
void printPattern(int n)
{
	int current = 1;
	for (int i = 1; i <= n; ++i) {
		 std::cout << current++;
		for (int j = 1; j < i; ++j) {
			std::cout << "*" << current++;
		}
		std::cout << "\n";
	}
	
	for (int i = n; i > 0; --i) {
		current -= i;
		std::cout << current;
		int tmp = current + 1;
		for (int j = 1; j < i; ++j) {
			std::cout << "*" << tmp++;
		}
		std::cout << "\n";
	}
}
bool flip_Numer(vector<int> &v, vector<int> &target) {
	bool result = false;
	if (v.size() != target.size()) {
		return false;
	}
	return false;
}
struct Node {
	int va;
	Node *next;
	Node(int v) : va(v), next(nullptr) {}
} ;
template<size_t n>
void ft(int (&array)[n], int sum) {
	vector<int> v(n,0);
	v.assign(array, array+n);
	sort(v.begin(), v.end());
	int f = 0;
	int e = n - 1;
	while (true) {
		auto t = v[f] + v[e];
		if (t == sum)
		{
			std::cout << v[f] << "+" << v[e] << "\n";
			return;
		}
		else if (t > sum)
		{
			--e;
		}
		else {
			++f;
		}
	}
	std::cout <<" can not find\n";
}
void ft1(int(&array)[10], int sum) {
}
void insertNode(Node* &root, int va) {
	auto* pt = &root;
	
	while ((*pt) != nullptr && (*pt)->va < va) {
		pt = &((*pt)->next);
	}
	auto new_node = new Node(va);
	new_node->next = *pt;
	*pt = new_node;
	
}
void merge(int(&a1)[7], int(&a2)[3]) {
	int i1 = 3, i2 = 2;
	int ri = 6;
	while ( i1 >=0 && i2 >=0) {
		if (a1[i1] <= a2[i2]) {
			a1[ri--] = a2[i2--];
		}
		else {
			a1[ri--] = a1[i1--];
		}
	}
	while (i2 >= 0) {
		a1[ri--] = a2[i2--];
	}
	while (i1 >= 0){
		a1[ri--] = a1[i1--];
	}
	for (auto i : a1) { std::cout << i << " "; }
	return;
}

void genString(const string &input) {
	auto total = count_if(input.begin(), input.end(), [](auto ch) { return ch == '?'; });
	int per = static_cast<int>( pow(2, total));
	int mask;
	for (int j = 0; j < per; ++j) {
		int pos = 0;
		for (decltype(input.size()) i = 0; i < input.size(); ++i) {
			if (input[i] == '?')
			{
				mask = static_cast<int>(pow(2, pos++));
				std::cout << ((mask&j) ? '1' : '0');
			}
			else {
				std::cout << input[i];
			}
		}
		std::cout << "\n";
	}
	
}
template<size_t n>
void find_se(int( &ar)[n]) {
	
	sort(ar, ar + n);
	int pv = ar[0];
	int len = 1;
	int max_len = 0;
	bool b = false;
	for (int i = 1;i < n; ++i) {
		if (ar[i] == pv) {
			++len;
		}
		else if (ar[i] == pv+1 && !b){
			b = true;
			++len;
		}
		else {
		
			if (len > max_len) {
				max_len = len;
			}
			len = 1;
			b = false;
		}
		pv = ar[i];
	}
	std::cout << "max_len " << max_len << "\n";
}
void display(Node* root) {
	auto cur = root;
	while (cur != nullptr) {
		std::cout << cur->va << " ";
		cur = cur->next;
	}
}
void revdisplay(Node* node) {
	if (node->next == nullptr){
		std::cout << node->va << " ";;
	}else {
		revdisplay(node->next);
		std::cout << node->va<< " ";
	}
}
const double ToDegress = 180.0 / M_PI;
const double view_angle = 45;
struct Coord {
	double x;
	double y;
};
struct GetRadisu {

	double operator()(const Coord &cor) {
		return atan(cor.x / cor.y) * 180.0 / M_PI;
	}
};

void GetViewingDirection(const vector<Coord> &coorinate) {
	vector<double> angles;
	angles.reserve(coorinate.size() * 2);

	std::transform(coorinate.begin(), coorinate.end(), back_inserter(angles), [](const auto& cor) {return atan2(cor.y, cor.x) * 180 / M_PI; });
	sort(angles.begin(), angles.end());
	auto dt = lower_bound(angles.begin(), angles.end(), angles.front() + view_angle);
	for (auto it = angles.begin(); it < dt; ++it) {
		angles.push_back(*it + 360);
	}
	vector<double>::difference_type count = 0;
	double best_degree = 0;
	auto size = angles.size();
	for (auto it = angles.begin(); it < angles.end() && *it < 360; ++it) {
		//auto r = upper_bound(it, angles.end(), *it + view_angle);
		auto c = distance(it, --upper_bound(it, angles.end(), *it + view_angle)) + 1;
		if (c > count) {
			count = c;
			best_degree = *it;
		}
	}
	std::cout << "best degree:" << best_degree << " with count " << count;
}
void PrintMissing(const vector<int> vec) {
	int idx = 0;
	int size = vec.size();
	for (int i = 0; i <= 99; ++i) {
		if (idx >= size || i < vec[idx])
			cout << i << "\n";
		else if (i == vec[idx]) {
			++idx;
		}
		else {
			auto j = lower_bound(vec.begin() + idx, vec.end(), i);
			if (j != vec.end()) {
				if (i == *j) {
					idx = j - vec.begin() + 1;
				}
				else {
					cout << i << "\n";
					idx = j - vec.begin();
				}
			}
			else {
				idx = size;
			}
		}
	}
}
void printStringValue(const string& str) {
	int val = 0;
	for_each(str.begin(), str.end(), [&val](auto ch) {
		switch (ch){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				++val;
				break;
			default:
				val += 2;}
	});
	std::cout << "printStringValue" << val << "\n";

}
template<size_t row, size_t col>
void find_neg_number(int ( & matrix )[row][col]) {
	size_t neg_count = 0;
	auto distance = col;
	for (size_t r = 0; r < row; ++r) {
		auto it = lower_bound(&matrix[r][0], &matrix[r][distance], 0);
		distance = it - &matrix[r][0];
		if (!distance)
			break;
		neg_count += distance;
		
	}
	std::cout << "find_neg_number:" << neg_count << "\n";
}
void quickSort(int *start, int *end) {
	auto left = start;
	auto right = end;
	auto mid_pos = left + (right - left) / 2;
	auto mid = *mid_pos;
	do {
		while (left < end && *left < mid) 
			++left;
		while (right > start && *right > mid) 
			--right;
		if (left <= right) {
			int t = *left;
			*left = *right;
			*right = t;
			++left;
			--right;
		}
		
	} while (left < right);
	if (right > start)
		quickSort(start,right);
	if (left < end)
		quickSort(left, end);
}
void binarySearch(int *start, int *end, int val) {

	if (end > start) {
		auto mid_pos = (start + (end - start) / 2);
		auto mid = *mid_pos;

		if (mid == val) {
			std::cout << "found!\n";
		}
		else if (mid > val) {
			if (mid_pos < end && mid_pos > start)
				binarySearch(start, mid_pos, val);
			else {
				std::cout << "not found!\n";
			}
		}
		else {
			if (mid_pos < end && mid_pos > start)
				binarySearch(mid_pos, end, val);
			else {
				std::cout << "not found!\n";
			}
		}
	}
	else {
		std::cout << "not found!\n";
	}
}

struct NodeN {
	NodeN(char a) : val(a) {}
	char val;
	vector<shared_ptr<NodeN>> Nodes;
};
stack<pair<NodeN,size_t>> dfsstack;
void PostOrderNodesNIterative(const NodeN &root) {
	dfsstack.push(make_pair(root,0));
	
	while (!dfsstack.empty()) {
		auto& t = dfsstack.top();
		if (t.first.Nodes.empty()
			|| t.second == t.first.Nodes.size()) {
			cout << t.first.val << " ";
			dfsstack.pop();
		}else {
			dfsstack.push(make_pair(*t.first.Nodes[t.second], 0));
			t.second += 1;
		}
	}
	
}
void PostOrderNodesN(const NodeN * root) {
	
	for (const auto& n : root->Nodes) {
		PostOrderNodesN(n.get());
	}
	cout << root->val << " ";
}
queue<NodeN> bfsq;
void BFSNodesN(const NodeN * root) {
	
	bfsq.push(*root);
	while (!bfsq.empty()) {
		auto h = bfsq.front();
		cout << h.val << " ";
		for (const auto& n : h.Nodes) {
			bfsq.push(*n.get());
		}
		bfsq.pop();
	}
	
	
}
unique_ptr<NodeN> MakeNTree() {
	auto a = make_unique<NodeN>('a');
	auto b = make_unique<NodeN>('b');
	auto c = make_unique<NodeN>('c');
	auto d = make_unique<NodeN>('d');
	auto e = make_unique<NodeN>('e');
	auto f = make_unique<NodeN>('f');
	auto g = make_unique<NodeN>('g');
	auto h = make_unique<NodeN>('h');
	auto i = make_unique<NodeN>('i');
	auto j = make_unique<NodeN>('j');
	auto k = make_unique<NodeN>('k');
	

	f.get()->Nodes.push_back(move(j));
	b.get()->Nodes.push_back(move(e));
	b.get()->Nodes.push_back(move(f));

	h.get()->Nodes.push_back(move(k));
	c.get()->Nodes.push_back(move(g));
	c.get()->Nodes.push_back(move(h));
	c.get()->Nodes.push_back(move(i));

	a.get()->Nodes.push_back(move(b));
	a.get()->Nodes.push_back(move(c));
	a.get()->Nodes.push_back(move(d));
	return a;
}
struct NodeR {
	int val;
	NodeR(int v) : val(v) {}
	NodeR *next;
	NodeR *random;
};
struct CheckResult
{
	
	pair<int, bool> next_node;
	pair<int, bool> randome_node;
	CheckResult(pair<int, bool> _n, pair<int, bool> _r) :
		next_node(_n), randome_node(_r) {}
};


int main()
{
	enum weekday {mon, tues};
	weekday we = mon;
	
	auto rootN = MakeNTree();
	//PostOrderNodesN(rootN.get());
	//BFSNodesN(rootN.get());
	PostOrderNodesNIterative(*rootN.get());
	int ar[3][4] = { {-6,-4,-2,-1} ,
					{ -2,-1,3,4 } ,
					{ -1,5,7,8 } 
				};
	//int a[10] = { 0,1,212,12,4,5,48,-12,-9,0 };
	int a[10] = { 0,1,1,1,12,1,1,1,1,1 };
	quickSort(a, a+9);
	for (auto i : a) {
		cout << i << " ";
	}
	//sort(a, a + 10);
	binarySearch(a, a + 10, 0);
	find_neg_number(ar);
	using storage = std::aligned_storage_t<1024, 16>;
	auto p = new storage;
	char buffer[] = "------------------------";
	void * pt = buffer;
	std::size_t space = sizeof(buffer) - 1;
	while (std::align(alignof(int), sizeof(char), pt, space)) {
		char* temp = static_cast<char*>(pt);
		*temp = '*'; ++temp; space -= sizeof(char);
		pt = temp;
	}
	std::cout << buffer << '\n';
	

	printStringValue("ab");
	printStringValue("abcd");
	printStringValue("abcde");
	vector<int> arrayOfInts = { 1,2,3,4,6,8,12,45,65,94 };
	PrintMissing(arrayOfInts);
	vector<Coord> cords = {
		Coord{2,0},
		Coord{100,0},
		Coord{ 1,0.8},
		Coord{1, 0.7}, 
		Coord{121,121},
		Coord{ 221,221 } ,
		Coord{ 1,8 },
		Coord{ 0,1 },
		Coord{ -1,12 } ,
		Coord{ -1,14},
		Coord{ -5,0 },
		Coord{-3,-4},
		Coord{ 1, -0.02},
		Coord{ 1, -0.02 }, 
	Coord{ 1, -0.02 } ,
	Coord{ 1, -0.02 } };
	GetViewingDirection(cords);
	int a3[] = { 6,10,6,7,8,9,7,1,-1,-1,2,8,8,8,8,8 };
	find_se(a3);
	int a1[] = { 4,10,11,20,0,0,0 };
	int a2[] = { 1,3,7 };
	merge(a1,a2 );
	genString("a?b?c?");
	int array[] = { 10, 5, 18, 40, 20, 15, 25, 0, 100, 50 };
	ft(array, 35);
	//ft1(array, 50);
	Node * root = nullptr;
	for (int i = 0; i < 10; i++) {
		insertNode(root,array[i]);
	}
	display(root);
	std::cout << "\n";
	revdisplay(root);
	printPatternq(4);
	printPattern(4);
	std::unordered_set<int> mymap;

	std::cout << "max_size = " << vowel.max_size() << std::endl;
	std::cout << "max_bucket_count = " << vowel.max_bucket_count() << std::endl;
	std::cout << "bucket_count = " << vowel.bucket_count() << std::endl;
	std::cout << "load_factor = " << vowel.load_factor() << std::endl;
	std::cout << "max_load_factor = " << vowel.max_load_factor() << std::endl;
	std::cout << getValue("a") << "\n";
	std::cout << getValue("ab") << "\n";
	std::cout << getValue("abcd") << "\n";
	std::cout << getValue("abcde") << "\n";
	list<int> l{ 2,4,8,12,25 };
	auto it = lower_bound(l.begin(), l.end(), 17);
	l.insert(it, 17);
    return 0;
}

