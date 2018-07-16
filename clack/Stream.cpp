#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;
//ostream
int main01()
{
	string tmp = "\n";
	ostream_iterator<int> intWriter(cout, tmp.c_str()); //分隔符的型别是char*

	*intWriter = 42;
	intWriter++;
	*intWriter = 77;
	intWriter++;
	*intWriter = -5;
	vector<int> coll;
	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout));
	cout << endl;

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, "<"));
	cout << endl;
}


int main02()
{
	istream_iterator<int> intReader(cin);

	istream_iterator<int> intReaderEOF;

	while (intReader != intReaderEOF)
	{
		cout << "once: " << *intReader << endl;
		cout << "once again: " << *intReader << endl;
		++intReader;
	}
}

int main()
{
	istream_iterator<string> cinPos(cin);

	ostream_iterator<string> coutPos(cout, " ");

	while (cinPos != istream_iterator<string>()){
		advance(cinPos, 2); //忽略接下来两个字符串

		if (cinPos != istream_iterator<string>()) {
			*coutPos++ = *cinPos++;
		}
	}
	cout << endl;
}









