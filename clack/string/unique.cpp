#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#include <iterator>
using namespace std;

class bothwhiteSpaces {
private:
	const locale& loc;
public:
	bothwhiteSpaces(const locale& l) :loc(l) {
	}
	bool operator() (char elem1, char elem2) {
		return isspace(elem1, loc) && isspace(elem2, loc);
	}
};



int main()
{
	string contents;
	cin.unsetf(ios::skipws);

	unique_copy(istream_iterator<char>(cin), istream_iterator<char>(),
		back_inserter(contents), bothwhiteSpaces(cin.getloc()));

	cout << contents;
}