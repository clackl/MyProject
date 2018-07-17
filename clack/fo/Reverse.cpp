#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<deque>
#include<iterator>
using namespace std;

void print(int elem)
{
	cout << elem << ' ';
}

int main01()
{
	list<int> coll;
	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}
	for_each(coll.begin(), coll.end(), print);
	cout << endl;

	for_each(coll.rbegin(), coll.rend(), print);

	cout << endl;

}
//rebgin9()��rend()������һ��Reverse�����򣩵�����

int main02()
{
	vector<int> coll;
	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}
	vector<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	cout << "pos: " << *pos << endl;

	vector<int>::reverse_iterator rpos(pos);

	cout << "rpos: " << *rpos << endl;

}
// 5 4 �������������������䲻�������,�������յ㣬�������������һ��

int main03()
{
	deque<int>coll;
	for (int i = 1; i < 9; ++i) {
		coll.push_back(i);
	}

	deque<int>::iterator pos1;
	pos1 = find(coll.begin(), coll.end(), 2);

	deque<int>::iterator pos2;
	pos2 = find(coll.begin(), coll.end(), 7);

	for_each(pos1, pos2, print);
	cout << endl;

	deque<int>::reverse_iterator rpos1(pos1);
	deque<int>::reverse_iterator rpos2(pos2);
	for_each(rpos2, rpos2, print);
	cout << endl;
}
//pos1,pos2������һ���뿪���䣬����2������7��
//�������תΪReverse������ʱ����������Ȼ��Ч�����ҿ��Ա�������
//2 3 4 5 6
//6 5 4 3 2


//��base()�����������ת������������
int main()
{
	list<int> coll;

	for (int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}

	list<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 5);

	cout << "pos: " << *pos << endl;

	list<int>::reverse_iterator rpos(pos);
	cout << "rpos: " << *rpos << endl;

	list<int>::iterator rrpos;
	rrpos = rpos.base();

	cout << "rrpos: " << *rrpos << endl;


}
