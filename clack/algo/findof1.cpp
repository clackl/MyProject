﻿#include "algostuff.hpp"
using namespace std;

//搜寻某些元素第一次出现地点
int main()
{
	vector<int> coll;
	list<int> searchcoll;

	INSERT_ELEMENT(coll, 1, 11);
	INSERT_ELEMENT(searchcoll, 3, 5);

	PRINT_ELEMENTS(coll, "coll: ");
	PRINT_ELEMENTS(searchcoll, "searchcoll: ");

	vector<int>::iterator pos;
	pos = find_first_of(coll.begin(), coll.end(), searchcoll.begin(), searchcoll.end());

	cout << "first element of searchcoll in coll is element "
		<< distance(coll.begin(), pos) + 1 << endl;

	vector<int>::reverse_iterator rpos;
	rpos = find_first_of(coll.rbegin(), coll.rend(), searchcoll.begin(), searchcoll.end());

	cout << "last element of searchcoll in coll is element "
		<< distance(coll.begin(), rpos.base()) << endl;

}