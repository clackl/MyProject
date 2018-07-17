#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

//һ���������ò���deque
//��Ҫ�����˰�����Ƴ�Ԫ��
//�������������ڵ�Ԫ��
//Ҫ�������ͷŲ���ʹ�õ�Ԫ��

//����ʵ��
int main()
{
	deque<string> coll;

	coll.assign(2, string("string"));
	coll.push_back("last string");
	coll.push_front("first string");

	copy(coll.begin(), coll.end(),
		ostream_iterator<string>(cout, "\n"));
	cout << endl;

	coll.pop_front();
	coll.pop_back();

	for (int i = 1; i < coll.size(); ++i) {
		coll[i] = "another " + coll[i];
	}

	coll.resize(4, "resized string");

	copy(coll.begin(), coll.end(),
		ostream_iterator<string>(cout, "\n"));
	return 0;
}






















int main01()
{
	deque<float>coll;
	for (int i = 1; i < 6; i++)
		coll.push_front(i*1.1);

	for (int i = 0; i < coll.size(); ++i) {
		cout << coll[i] << ' ';
	}
	cout << endl;
}
