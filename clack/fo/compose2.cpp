#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "print.hpp"
#include "compose21.hpp"
using namespace std;

int main()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);

	vector<int>::iterator pos;
	pos = remove_if(coll.begin(), coll.end(), 
		compose_f_gx_hx(logical_and<bool>(),bind2nd(greater<int>(), 4),
											bind2nd(less<int>(), 7)));

	coll.erase(pos, coll.end());
	PRINT_ELEMENTS(coll);
}