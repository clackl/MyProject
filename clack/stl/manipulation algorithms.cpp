//ָ�ᡰɾ�������Ż��޸�Ԫ�ء����㷨

//remove()��ĳ������ɾ��Ԫ��,������ɾ������Ԫ��
#include<iostream>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() //listԪ�ص���remove()������ɾ��Ԫ��
{
	list<int> coll;

	for (int i = 1; i <= 6; i++) {
		coll.push_front(i);
		coll.push_back(i);
	}
	//���õķ�ʽ
	coll.erase(remove(coll.begin(), coll.end(), 3),coll.end());
	//�õķ�ʽ
	coll.remove(4);
}


int main03()//����ʽ����ɾ��Ԫ��
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

int main02() //�Ľ���
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

	//�õ�һ�����ɾ��Ԫ��
	//coll.erase(remove(coll.begin(),coll.end(),3),coll.end());
}


int main01() //��û�иı�Ԫ������
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

