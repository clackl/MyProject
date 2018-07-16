#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
	cout << "list1: ";
	copy(l1.begin(), l1.end(), 
		ostream_iterator<int>(cout, " "));
	cout << endl << "list2: ";
	copy(l2.begin(), l2.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main()
{
	list<int> list1, list2;

	for (int i = 0; i < 6; i++) {
		list1.push_back(i);
		list2.push_front(i);
	}
	printLists(list1, list2);

	list2.splice(find(list2.begin(), list2.end(), 3), list1);

	printLists(list1, list2);

	list2.sort();
	list1 = list2;

	list2.unique();
	printLists(list1, list2);

	list1.merge(list2);
	printLists(list1, list2);
}





















int main01()
{
	list<char> coll;

	for (char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	while (!coll.empty()) {
		cout << coll.front() << ' ';
		coll.pop_front();
	}
	cout << endl;
}