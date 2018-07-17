#include <iostream>

using namespace std;

template<class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	typename T::const_iterator pos;

	cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		cout << *pos << ' ';
	}
	cout << endl;
}


//#include<iostream>
//#include<list>
//#include<algorithm>
//
//using namespace std;
//int main()
//{
//	list<int> coll;
//	for (int i = 1; i < 9; ++i) {
//		coll.push_back(i);
//	}
//}