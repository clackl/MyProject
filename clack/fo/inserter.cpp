#include<iostream>
#include<vector>
#include<list>
#include<set> 
#include<algorithm>
#include"print.cpp"
using namespace std;
//backinserter
int main01()
{
	vector<int> coll;
	back_insert_iterator<vector<int> >iter(coll);

	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	PRINT_ELEMENTS(coll);

	back_inserter(coll) = 44;
	back_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);
	coll.reserve(2 * coll.size());
	copy(coll.begin(), coll.end(), back_inserter(coll));
	PRINT_ELEMENTS(coll);
}
//copy()֮ǰȷ�����㹻��Ŀռ䣬��Ϊback inserter�ڰ���Ԫ��ʱ��
//���ܻ����ָ���vector������������ʧЧ


//Front inserters
int main02()
{
	list<int> coll;
	front_insert_iterator<list<int> >iter(coll);

	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	PRINT_ELEMENTS(coll);

	front_inserter(coll) = 44;
	front_inserter(coll) = 55;

	PRINT_ELEMENTS(coll);
	
	copy(coll.begin(), coll.end(), front_inserter(coll));
	PRINT_ELEMENTS(coll);
}


//General inserters
int main()
{
	set<int> coll;

	insert_iterator<set<int> >iter(coll, coll.begin());
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	PRINT_ELEMENTS(coll,"set: ");

	inserter(coll, coll.end()) = 44;
	inserter(coll, coll.end()) = 55;

	PRINT_ELEMENTS(coll, "set: ");

	list<int> coll2;
	copy(coll.begin(), coll.end(), inserter(coll2,coll2.begin()));
	PRINT_ELEMENTS(coll2, "list: ");

	copy(coll.begin(), coll.end(), inserter(coll2, ++coll2.begin()));
	PRINT_ELEMENTS(coll2, "list: ");
	return 0;
}