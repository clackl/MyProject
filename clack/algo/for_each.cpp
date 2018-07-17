#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "algostuff.hpp"
using namespace std;

//使用for_each的返回值
class MeanValue1 {
private:
	long num;
	long sum;
public:
	MeanValue1() :num(0), sum(0) {
	}

	void operator() (int elem) {
		num++;
		sum += elem;
	}

	operator double() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}

	operator int() {
		return static_cast<int>(sum) + static_cast<int>(num);
	}
};

int main()
{
	vector<int> coll;
	INSERT_ELEMENT(coll, 1, 8);

	double mv = for_each(coll.begin(), coll.end(), MeanValue1());
	int mv1 = for_each(coll.begin(), coll.end(), MeanValue1());
	cout << "mean value: " << mv << endl;

}



//利用仿函数来改变每一个元素内容
template<class T>
class AddValue {
private:
	T theValue;
public:
	AddValue(const T& v) :theValue(v) {
	}

	void operator() (T& elem) const {
		elem += theValue;
	}
};

int main04()
{
	vector<int> coll;

	INSERT_ELEMENT(coll, 1, 9);
	PRINT_ELEMENTS(coll);

	for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
	PRINT_ELEMENTS(coll);

}




class MeanValue {
private:
	long num;
	long sum;
public:
	MeanValue():num(0), sum(0) {
	}

	void operator() (int elem) {
		num++;
		sum += elem;
	}

	double value() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

int main03()
{
	vector<int> coll;
	for (int i = 1; i <= 8; i++) {
		coll.push_back(i);
	}

	MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
	cout << "mean value: " << mv.value() << endl;

}




int square(int value)
{
	return value * value;
}

int main02()
{
	set<int> coll1;
	vector<int>coll2;
	for (int i = 1; i <= 9; ++i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1, "initialized: ");

	transform(coll1.begin(), coll1.end(), back_inserter(coll2), square);

	PRINT_ELEMENTS(coll2, "squared: ");

}



void print(int elem)
{
	cout << elem << ' ';
}

int main01()
{
	vector<int> coll;
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	for_each(coll.begin(), coll.end(), print);
	cout << endl;
}


