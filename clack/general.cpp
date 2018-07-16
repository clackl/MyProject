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
//�º����Ǵ�ֵ��ʽ���ݵģ��ŵ��ǿ��Դ��ݳ�������ʱ���ʽ��
//ȱ���޷��ı�º�����״̬
int main01()
{
	list<int> coll;
	//generate_n��generate�㷨�����ǲ�����ֵ�Թ�д��Ⱥ��֮��
	generate_n(back_inserter(coll), 9, IntSquence(1));
	PRINT_ELEMENTS(coll);
	generate(++coll.begin(), --coll.end(), IntSquence(42));
	PRINT_ELEMENTS(coll);
}

//Ϊ�����Դ���ַ��ʽ���ݷº�������Ҫ�ڵ����㷨ʱ������º���ʱ��ַ�ͱ�
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