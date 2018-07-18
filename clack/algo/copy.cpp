#include "algostuff.hpp"
#include <iterator>
using namespace std;

//使用copy()作为标准输入和标准输出之间的数据过滤器，程序读取strings，并一行一个方式打印
int main()
{
	copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, "\n"));
}


//copy_backward 从后往前赋值
int main02()
{
	vector<char> source(10, '-');
	for (int c = 'a'; c <= 'f'; c++) {
		source.push_back(c);
	}
	source.insert(source.end(), 10, '-');
	PRINT_ELEMENTS(source, "source: ");

	vector<char> c1(source.begin(), source.end());
	copy(c1.begin() + 10, c1.begin() + 16, c1.begin() + 7);
	PRINT_ELEMENTS(c1, "c1: ");

	vector<char> c2(source.begin(), source.end());
	copy_backward(c2.begin() + 10, c2.begin() + 16, c2.begin() + 19);

	PRINT_ELEMENTS(c2, "c2: ");
}




int main01()
{
	vector<int> coll1;
	list<int> coll2;

	INSERT_ELEMENT(coll1, 1, 9);

	copy(coll1.begin(), coll1.end(), back_inserter(coll2));

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy(coll1.rbegin(), coll1.rend(), coll2.begin());

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}