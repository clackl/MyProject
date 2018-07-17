#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#include "fopow.hpp"

int main()
{
	vector<int> coll;

	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}

	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		bind1st(fopow<float, int>(), 3));
	cout << endl;

	transform(coll.begin(), coll.end(),
		ostream_iterator<int>(cout, " "),
		bind2nd(fopow<float, int>(), 3));
	cout << endl;
}