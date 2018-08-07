#include <iostream>
#include <fstream>
using namespace std;

int rw1()
{
	filebuf buffer;
	ostream output(&buffer);
	istream input(&buffer);
	buffer.open("example.txt", ios::in | ios::out | ios::trunc);

	for (int i = 1; i <= 4; ++i) {
		output << i << ". line" << endl;
		input.seekg(0);
		char c;
		/*while (input.get(c)) {
			cout.put(c);
		}*/
		cout << input.rdbuf();
		cout << endl;
		input.clear(); //clear eofbit and failbit
	}
	return 0;
}

int rw101()
{
	fstream file("example.txt", ios::in | ios::out | ios::trunc);
	for (int i = 1; i <= 4; ++i) {
		file << i << ". line" << endl;
		file.seekg(0);
		char c;
		while (file.get(c)) {
			cout.put(c);
		}
		cout << endl;
		file.clear(); //clear eofbit and failbit
	}
	return 0;
}
