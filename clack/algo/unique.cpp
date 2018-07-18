#include "algostuff.hpp"
using namespace std;


bool bothSpaces(char elem1, char elem2) {
	return elem1 == ' '&&elem2 == ' ';
}

int main()
{
	cin.unsetf(ios::skipws);

	unique_copy(istream_iterator<char>(cin), istream_iterator<char>(),
		ostream_iterator<char>(cout), bothSpaces);
}



bool difference(int elem1, int elem2) {
	return elem1 + 1 == elem2 || elem1 - 1 == elem2;
}

//复制过程中移除重复元素
int main02()
{
	int source[] = { 1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4 };
	int sourceNum = sizeof(source) / sizeof(source[0]);
	list<int> coll;

	copy(source, source + sourceNum, back_inserter(coll));

	PRINT_ELEMENTS(coll);

	unique_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	unique_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "),difference);
	cout << endl;

}



//移除重复元素
int main01()
{
	int source[] = { 1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4 };

	int sourceNum = sizeof(source)/sizeof(source[0]);

	list<int> coll;

	copy(source, source + sourceNum, back_inserter(coll));

	PRINT_ELEMENTS(coll);

	list<int>::iterator pos;

	pos = unique(coll.begin(), coll.end());

	copy(coll.begin(), pos, ostream_iterator<int>(cout, " "));
	cout << "\n\n";

	copy(source, source + sourceNum, coll.begin());
	PRINT_ELEMENTS(coll);

	coll.erase(unique(coll.begin(), coll.end(), greater<int>()), coll.end());
	PRINT_ELEMENTS(coll);
}