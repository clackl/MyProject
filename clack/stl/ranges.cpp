#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() //������������䣬����ʱ��ȷ���ڶ�������������ӵ��Ԫ�ظ������ٺ͵�һ���������ͬ
{
	list<int> coll1;
	vector<int> coll2;

	for (int i = 1; i <= 9; i++)
		coll1.push_back(i);

	coll2.resize(coll1.size());

	copy(coll1.begin(), coll1.end(), coll2.begin());

	deque<int> coll3(coll1.size());

	copy(coll1.begin(), coll1.end(), coll3.begin());
}

















int main01()
{
	list<int>  coll;
	list<int>::iterator pos;

	for (int i = 20; i <= 40; i++) {
		coll.push_back(i);
	}

	pos = find(coll.begin(), coll.end(), 3);

	reverse(pos, coll.end());

	list<int>::iterator pos25, pos35;
	pos25 = find(coll.begin(), coll.end(), 25);

	pos35 = find(coll.begin(), coll.end(), 35);

	cout << "max: " << *max_element(pos25, pos35) << endl;

	cout << "max: " << *max_element(pos25, ++pos35) << endl;
	return 0;
}