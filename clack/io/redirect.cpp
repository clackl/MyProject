#include <iostream>
#include <fstream>
using namespace std;

void redirect(ostream&);
int redirectmain()
{
	cout << "the first row" << endl;
	redirect(cout);
	cout << "the last row" << endl;
	return 0;
}

void redirect(ostream& strm)
{
	strm << "输出到屏幕" << endl;
	ofstream file("redirect.txt");
	streambuf* strm_buffer = strm.rdbuf(); //保存流对象

	strm.rdbuf(file.rdbuf()); //重定向到txt

	file << "one row for the file" << endl; //输出到txt文件中
	strm << "one row for the stream" << endl; //输出到txt文件中

	strm.rdbuf(strm_buffer); //恢复到流对象
	strm << "输出到屏幕" << endl;
}

