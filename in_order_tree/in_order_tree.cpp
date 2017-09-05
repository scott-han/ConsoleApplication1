// in_order_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <queue>
struct node
{
	int val;
	node *left;
	node *right;
	
};
void bfs(node *root)
{
	std::queue<node*> q;
	
	auto c = root;
	while (c != nullptr)
	{
		
		std::cout << c->val << " ";
		if (c->left != nullptr)
			q.push(c->left);
		if (c->right != nullptr)
			q.push(c->right);
		if (q.empty())
		{
			c = nullptr;
		}
		else {
			c = q.front();
			q.pop();
		}
		
	}
	std::cout << std::endl;
}
void print_in_order_tree(node *root)
{
	if (root->left)
	{
		print_in_order_tree(root->left);
	}
	std::cout << root->val << " ";
	if (root->right)
	{
		print_in_order_tree(root->right);
	}
}
void build_in_order_tree(node *&np, int val)
{
	if (np == nullptr)
	{
		np = new node{ val, nullptr, nullptr };
	}
	else
	{
		
		if (val > np->val)
		{
			if (np->right == nullptr)
			{
				np->right = new node{ val,nullptr,nullptr };
			}
			else
			{
				build_in_order_tree(np->right,val);
			}
		}
		else if (val < np->val) {
			if (np->left == nullptr)
			{
				np->left = new node{ val,nullptr,nullptr };
			}
			else {
				build_in_order_tree(np->left, val);
			}
		}
		else {
			throw  "duplicated value";
		}
	}

}
using namespace std;
int main()
{
	std::list<int> l(10);
	std::iota(l.begin(), l.end(), 0);

	std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
	//std::vector<int> v2(10);
	// can't use shuffle on a list (requires random access), but can use it on a vector
	std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });
	//transform(v.begin(), v.end(),v2.begin(), [](auto& e) {return ++e; });
	for (auto val : v) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	node* root = nullptr;
	for (auto val : v) {
		build_in_order_tree(root,val);
	}
	bfs(root);
	
	print_in_order_tree(root);
    return 0;
}

