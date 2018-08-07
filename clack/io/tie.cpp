#include <iostream>
#include <fstream>
using namespace std;

int tie1() 
{
	ofstream ofs;
	ofs.open("test.txt");

	cin.tie(&ofs); //注释掉这一行试试看
	*cin.tie() << "There will be some text:";
	char c;
	while (cin >> c) {
		ofs << c;
	}

	ofs.close();

	return 0;
}


int tie2() {
	ostream *prevstr;
	ofstream ofs;
	ofs.open("test.txt");
	cout << "tie example:\n";

	*cin.tie() << "This is inserted into cout";
	prevstr = cin.tie(&ofs);
	*cin.tie() << "This is inserted into the file";
	cin.tie(prevstr);

	ofs.close();

	return 0;
}