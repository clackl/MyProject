//指会“删除或重排或修改元素”的算法

//remove()自某个区间删除元素,不适用删除所有元素
#include<iostream>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() //list元素调用remove()真正的删除元素
{
	list<int> coll;

	for (int i = 1; i <= 6; i++) {
		coll.push_front(i);
		coll.push_back(i);
	}
	//不好的方式
	coll.erase(remove(coll.begin(), coll.end(), 3),coll.end());
	//好的方式
	coll.remove(4);
}


int main03()//关联式容器删除元素
{
	set<int> coll;
	for (int i = 1; i <= 9; i++) {
		coll.insert(i);
	}
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout," "));
	cout << endl;

	int num = coll.erase(3);

	cout << "number if removed elements: " << num << endl;

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

int main02() //改进版
{
	list<int> coll;

	for (int i = 1; i <= 6; i++) {
		coll.push_front(i);
		coll.push_back(i);
	}

	cout << "pre: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);
	
	copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "number if removed elements: " << distance(end, coll.end()) << endl;

	coll.erase(end, coll.end());

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//用单一语句来删除元素
	//coll.erase(remove(coll.begin(),coll.end(),3),coll.end());
}


int main01() //并没有改变元素数量
{
	list<int> coll;

	for (int i = 1; i <= 6; i++) {
		coll.push_front(i);
		coll.push_back(i);
	}

	cout << "pre: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	remove(coll.begin(), coll.end(), 3);
	cout << "post: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

