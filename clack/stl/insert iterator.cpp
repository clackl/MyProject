#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	list<int> coll1;

	for (int i = 1; i <= 9; i++) {
		coll1.push_back(i);
	}

	vector<int>coll2;
	copy(coll1.begin(), coll1.end(), back_inserter(coll2)); //只有提供push_back()才能使用back_inserter()   vector,deque,list

	deque<int> coll3;
	copy(coll1.begin(), coll1.end(), front_inserter(coll3));//只有提供push_front()才能使用front_inserter()   deque,list

	set<int> coll4;
	copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));




}
