#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> coll;

	for (int i = 0; i < 9; i++) {
		coll.push_back(i);
	}
	//rbegin() ���������� rend() ��������յ�
	copy(coll.rbegin(), coll.rend(), ostream_iterator<int>(cout, " "));
	//*coll.rend() û�ж���
	//*coll.end() Ҳû�ж���
	//ʹ��operator--������ǰһ��Ԫ��
	cout << endl;
}

