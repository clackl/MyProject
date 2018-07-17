#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <iterator>
using namespace std;


//vector没有提供函数可以移除“与某值相等的所有元素”，需要用到算法
void f(){
	std::vector<int> coll;
	int val = 10;
	coll.erase(remove(coll.begin(), coll.end(), val), 
		coll.end());
}

//移除“与某值相等的第一个元素”
void f1() {
	std::vector<int> coll;
	std::vector<int>::iterator pos;
	pos = find(coll.begin(), coll.end(), 10);
	if (pos != coll.end()) {
		coll.erase(pos);
	}
}

//将Vector当做一般的array使用
void f2() {
	std::vector<char>v;
	v.resize(41);
	strcpy(&v[0], "hello clack");
	printf("%s\n", &v[0]);
}
//不要把迭代器当做第一个元素的地址来传递，vector由实作版本定义，也许不是一个一般指针
//printf("%s\n",v.begin());//err
//printf("%s\n",&v[0]); //ok

//运用实列
int main()
{
	vector<string> sentence;
	sentence.reserve(5);

	sentence.push_back("hello");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");

	copy(sentence.begin(), sentence.end(),
		ostream_iterator<string>(cout," "));
	cout << endl;

	cout << " max_size(): " << sentence.max_size() << endl;
	cout << " size(): " << sentence.size() << endl;
	cout << " capacity(): " << sentence.capacity() << endl;

	//swap second and fourth element
	swap(sentence[1], sentence[3]);

	//insert element "alaways" before elemnet "?"
	sentence.insert(find(sentence.begin(), sentence.end(), "?"), 
		                   "alaways");

	//assign "!" to the last element
	sentence.back() = "!";

	//print elements separated with spaces
	copy(sentence.begin(), sentence.end(),
		ostream_iterator<string>(cout, " "));
	cout << endl;

	//print "technical data" again
	cout << " max_size(): " << sentence.max_size() << endl;
	cout << " size(): " << sentence.size() << endl;
	cout << " capacity(): " << sentence.capacity() << endl;

	return 0;
}
