#include <fstream>
#include <iostream>
using namespace std;

int cat1(int argc, char* argv[])
{
	ifstream file;
	for (int i = 1; i < argc; ++i) {
		file.open(argv[i]);
		char c;
		while (file.get(c)) {
			cout.put(c);
		}
	}
	file.clear();
	file.close();
	return 0;
}


void printFileTwice(const char *filename)
{
	ifstream file(filename);
	cout << file.rdbuf();
	file.seekg(0);
	cout << file.rdbuf();
	//file.rdbuf()被用来打印文件内容，此时是直接操作stream缓冲区，并不会改变stream状态
}

int cat2(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i) {
		printFileTwice(argv[i]);
	}
	return 0;
}