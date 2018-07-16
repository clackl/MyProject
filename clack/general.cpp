#include<iostream>
#include<list>
#include<algorithm>
#include"print.cpp"
using namespace std;

class IntSquence {
private:
	int value;
public:
	IntSquence(int initialValue) :value(initialValue) {
	}

	int operator() () {
		return value++;
	}
};
//仿函数是传值方式传递的，优点是可以传递常量或暂时表达式，
//缺点无法改变仿函数的状态
int main01()
{
	list<int> coll;
	//generate_n和generate算法作用是产生数值以供写入群集之内
	generate_n(back_inserter(coll), 9, IntSquence(1));
	PRINT_ELEMENTS(coll);
	generate(++coll.begin(), --coll.end(), IntSquence(42));
	PRINT_ELEMENTS(coll);
}

//为了能以传地址方式传递仿函数，需要在调用算法时，明标仿函数时地址型别
int main()
{
	list<int> coll;
	IntSquence seq(1);

	generate_n <back_insert_iterator<list<int> >,int, IntSquence&>
				(back_inserter(coll), 4, seq);
	PRINT_ELEMENTS(coll);

	generate_n(back_inserter(coll), 4, IntSquence(42));
	PRINT_ELEMENTS(coll);

	generate_n(back_inserter(coll), 4, seq);
	PRINT_ELEMENTS(coll);

	generate_n(back_inserter(coll), 4, seq);
	PRINT_ELEMENTS(coll);
}