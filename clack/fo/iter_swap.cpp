#include<iostream>
#include<list>
#include<algorithm>
#include"print.cpp"
using namespace std;

int main()
{
	list<int>coll;
	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);

	iter_swap(coll.begin(), ++coll.begin());

	PRINT_ELEMENTS(coll);

	iter_swap(coll.begin(), --coll.end());

	PRINT_ELEMENTS(coll);
}
//�����vector��Ϊ������һ������´˳����޷����У���Ϊ++coll.begin()��
//--coll.end()�õ�������ʱָ��

