// nest_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>

using namespace std;

/* start of Enclosing class declaration */
class Enclosing {

	int x;
public:
	/* start of Nested class declaration */
	class Nested {
		int y;
		void NestedFun(Enclosing *e) {
			cout << e->x;  // works fine: nested class can access 
						   // private members of Enclosing class
		}
	}; // declaration Nested class ends here
}; // declaration Enclosing class ends here

//   /* start of Enclosing class declaration */
//class Enclosing1 {
//
//	int x;
//
//	/* start of Nested class declaration */
//	class Nested {
//		int y;
//	}; // declaration Nested class ends here
//
//	void EnclosingFun(Nested *n) {
//		cout << n->y;  // Compiler Error: y is private in Nested
//	}
//}; // declaration Enclosing class ends here
int main()
{
	Enclosing e;
	Enclosing::Nested d;
    return 0;
}

