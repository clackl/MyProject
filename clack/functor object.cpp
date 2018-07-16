#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <algorithm>
#include "print.cpp"
using namespace std;

int main()
{
	set<int, greater<int> >coll1;
	deque<int> coll2;
	for (int i = 1; i <= 9; ++i) {
		coll1.insert(i);
	}
	PRINT_ELEMENTS(coll1, "initialized: ");

	transform(coll1.begin(), coll1.end(), 
		back_inserter(coll2), bind2nd(multiplies<int>(), 10));

	PRINT_ELEMENTS(coll2, "transformed: ");

	replace_if(coll2.begin(), coll2.end(), 
		bind2nd(equal_to<int>(), 70), 42);

	PRINT_ELEMENTS(coll2, "replace: ");

	coll2.erase(remove_if(coll2.begin(), coll2.end(),
		bind2nd(less<int>(), 50)), coll2.end());

	PRINT_ELEMENTS(coll2, "removed: ");

}










class AddValue {
private:
	int theValue;
public:
	AddValue(int v):theValue(v) {
	}
	void operator() (int& elem) const {
		elem += theValue;
	}
};

int main02()
{
	list<int> coll;
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll, "initialized: ");

	for_each(coll.begin(), coll.end(), AddValue(10));

	PRINT_ELEMENTS(coll, "after adding 10: ");

	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));

	PRINT_ELEMENTS(coll, "after adding first element: ");

	return 0;
}



















class PrintInt {
public:
	void operator() (int elem) const {
		cout << elem << ' ';
	}
};

int main01() 
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}
	 //PrintInt产生一个临时对象，当做for_each()算法的一个参数。
	//反函数比一般函数速度快
	for_each(coll.begin(), coll.end(), PrintInt());
	cout << endl;
}