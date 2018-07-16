#include <iostream>
#include <vector>
#include <string>
#include <iterator> //istream_iterator
#include <algorithm>
using namespace std;

int main()
{
	vector<string> coll;

	istream_iterator<string>is(cin);
	istream_iterator<string> eof;
	copy(is, eof, back_inserter(coll));

	sort(coll.begin(), coll.end());

	unique_copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}