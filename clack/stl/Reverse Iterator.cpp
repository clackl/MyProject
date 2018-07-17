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
	//rbegin() 逆向遍历起点 rend() 逆向遍历终点
	copy(coll.rbegin(), coll.rend(), ostream_iterator<int>(cout, " "));
	//*coll.rend() 没有定义
	//*coll.end() 也没有定义
	//使用operator--后退至前一个元素
	cout << endl;
}

