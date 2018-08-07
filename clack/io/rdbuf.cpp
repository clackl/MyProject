#include <iostream>
#include <fstream>
using namespace std;

int rdbuf1()
{
	ostream hexout(cout.rdbuf());
	hexout.setf(ios::hex, ios::basefield);
	hexout.setf(ios::showbase);
	hexout << "hexout: " << 177 << " ";
	cout << "cout: " << 177 << " ";
	hexout << "hexout: " << -49 << " ";
	cout << "cout: " << -49 << " ";
	return 0;
}

void hexMultiplicationTable(std::streambuf* buffer, int num)
{
	ostream hexout(buffer);
	hexout << hex << showbase;
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= 10; ++j) {
			hexout << i * j << ' ';
		}
		hexout << endl;
	}
}// does NOT close buffer

//优点在于格式修改后不必恢复其原先状态
//缺点在于stream对象的构造和析构会有更多额外的开销，同时，stream对象析构时并不清空缓冲区，必须手工进行
int rdbuf2() 
{
	int num = 5;
	cout << "we print " << num << " line hexadecimal" << endl;
	hexMultiplicationTable(cout.rdbuf(), num);
	cout << "That was the output of " << num << "hexadecimal lines " << endl;
	return 0;
}

