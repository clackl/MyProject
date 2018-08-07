#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int writeCharsetToFile(const string& filename);
int outputFile(const string& filename);

int charset()
{
	int ret=0;
	ret = writeCharsetToFile("charset.txt");
	if (ret != 0) {
		return -1;
	}
	ret =outputFile("charset.txt");
	if (ret != 0) {
		return -1;
	}
	return 0;
}

int writeCharsetToFile(const string& filename)
{
	ofstream file(filename.c_str());
	if (!file) {
		cerr << "can't open output file \"" << filename << "\"" << endl;
		return -1;
	}
	for (int i = 32; i < 256; i++) {
		file << "value: " << setw(3) << i << " " << "char: " << static_cast<char>(i) << endl;
	}
	return 0;
}

int outputFile(const string& filename)
{
	ifstream file(filename.c_str());
	if (!file) {
		cerr << "can't open input file\"" << filename << "\"" << endl;
		return -1;
	}
	char c;
	while (file.get(c)) {
		cout.put(c);
	}
	return 0;
}