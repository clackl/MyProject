#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//vector<int> coll1;
	vector<int> coll1(10);
	vector<int> coll2;

	//runtime error coll1û��Ԫ�أ���ʼ�����յ�ĺ���
	vector<int>::iterator pos = coll1.begin();
	reverse(++pos, coll1.end());

	for (int i = 1; i <= 9; i++) {
		coll2.push_back(i);
	}

	//runtime error //��д�����ڵ�Ԫ�أ�coll1����С��coll2
	copy(coll2.begin(), coll2.end(), coll1.begin());

	//runtime error ��ʼ�ͽ����������
	//copy(coll1.begin(), coll2.end(), coll1.end());

	return 0;
}