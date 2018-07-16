#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "print.cpp"
using namespace std;

int square(int value)
{
	return value * value;
}

int main()
{
	set<int> coll1;
	vector<int>coll2;
	for (int i = 1; i <= 9; ++i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1, "initialized: ");

	transform(coll1.begin(), coll1.end(), back_inserter(coll2), square);

	PRINT_ELEMENTS(coll2, "squared: ");

}









void print(int elem)
{
	cout << elem << ' ';
}

int main01()
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	for_each(coll.begin(), coll.end(), print);
	cout << endl;
}


