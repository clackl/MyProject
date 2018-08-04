#include <iostream>
#include <queue>
#include <string>
using namespace std;

#include "Queue.hpp"

int main()
{
	try {
		Queue<string> q;
		q.push("These ");
		q.push("are ");
		q.push("more than ");

		cout << q.pop();
		cout << q.pop();

		q.push("four ");
		q.push("words!");
		q.pop();

		cout << q.pop();
		cout << q.pop() << endl;
		

		cout << "number of elelments in the queue: " << q.size() << endl;
		cout << q.pop() << endl;
	}
	catch (const exception& e) {
		cerr << "EXCEPTION: " << e.what() << endl;
	}
}










//int main01()
//{
//	queue<string> q;
//	q.push("These ");
//	q.push("are ");
//	q.push("more than ");
//
//	cout << q.front();
//	q.pop();
//	cout << q.front();
//	q.pop();
//
//	q.push("four ");
//	q.push("words!");
//	q.pop();
//
//	cout << q.front();
//	q.pop();
//	cout << q.front() << endl;
//	q.pop();
//
//	cout << "number of elelments in the queue: " << q.size() << endl;
//}