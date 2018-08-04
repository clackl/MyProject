#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	const string hello("Hello,how are you?");
	string s(hello.begin(), hello.end());
	string::iterator pos;
	for (pos = s.begin(); pos != s.end(); ++pos) {
		cout << *pos;
	}
	cout << endl;

	reverse(s.begin(), s.end());
	cout << "reverse: " << s << endl;

	sort(s.begin(), s.end());
	cout << "ordered: " << s << endl;
	s.erase(unique(s.begin(), s.end()), s.end());
	cout << "no duplicates; " << s << endl;  
}



bool nocase_compare(char c1, char c2) {
	return toupper(c1) == toupper(c2);
}

int main01()
{
	string s1("this is a string");
	string s2("STRING");

	if (s1.size() == s2.size() && equal(s1.begin(), s1.end(), s2.begin(), nocase_compare)) {
		cout << "the strings are equal" << endl;
	}
	else {
		cout << "the strings are not equal" << endl;
	}

	string::iterator pos;
	pos = search(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
	if (pos == s1.end()) {
		cout << "s2 is not a substring of s1" << endl;
	}
	else {
		cout << ' " ' << s2 << "\" is a substring of \"" << s1 << "\"(at index " << pos - s1.begin() << ")" << endl;
	}

}