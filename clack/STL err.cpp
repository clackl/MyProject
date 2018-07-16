#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//vector<int> coll1;
	vector<int> coll1(10);
	vector<int> coll2;

	//runtime error coll1没有元素，开始是在终点的后面
	vector<int>::iterator pos = coll1.begin();
	reverse(++pos, coll1.end());

	for (int i = 1; i <= 9; i++) {
		coll2.push_back(i);
	}

	//runtime error //重写不存在的元素，coll1区间小于coll2
	copy(coll2.begin(), coll2.end(), coll1.begin());

	//runtime error 开始和结束区间错误
	//copy(coll1.begin(), coll2.end(), coll1.end());

	return 0;
}