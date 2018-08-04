#include <iostream>
#include <stack>
using namespace std;

#include "Stack.hpp"


int main()
{
	try {
		Stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);


		cout << st.pop() << ' ';
		cout << st.pop() << ' ';

		st.top() = 77;

		st.push(4);
		st.push(5);

		st.pop();

		cout << st.pop() << ' ';
		cout << st.pop() << endl;
		cout << st.pop() << endl;

	}
	catch (const exception& e) {
		cerr << "EXCEPTION: " << e.what() << endl;
	}
}














//int main01()
//{
//	stack<int> st;
//
//	st.push(1);
//	st.push(2);
//	st.push(3);
//
//	cout << st.top() << ' ';
//	st.pop();
//	cout << st.top() << ' ';
//	st.pop();
//
//
//	st.top() = 77;
//
//	st.push(4);
//	st.push(5);
//
//	st.pop();
//	while (!st.empty()) {
//		cout << st.top() << ' ';
//		st.pop();
//	}
//	cout << endl;
//}