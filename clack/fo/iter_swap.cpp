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
//如果以vector作为容器，一般情况下此程序无法运行，因为++coll.begin()和
//--coll.end()得到的是暂时指针

