#include <iostream>
#include <set>
#include <iterator>  //distance

using namespace std;

//sets和Multisets安插函数返回值型别不同
//sets提供如下接口：
//pair<iterator,bool> insert(const value_type& elem);
//iterator            insert(iterator pos_hint,const value_type& elem);

//multiset提供如下接口
//iterator insert(const value_type& elem);
//iterator insert(iterator pos_hint, const value_type& elem);

//原因：Multisets允许元素重复，而sets不允许，因此安插一个已经有了的元素到set内会失败
//所以set的返回值是以pair组织起来的两个值

//运用实例
int main()
{
	typedef multiset<int, greater<int> >IntSet;  //降序

	IntSet coll1;

	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);

	IntSet::iterator pos;
	for (pos = coll1.begin(); pos != coll1.end(); ++pos) {
		cout << *pos << ' ';
	}
	cout << endl;

	IntSet::iterator ipos = coll1.insert(4);
	cout << "4 inserted as element " <<
		distance(coll1.begin(), ipos) + 1 << endl;

	multiset<int> coll2(coll1.begin(), coll1.end());  //升序

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	coll2.erase(coll2.begin(), coll2.find(3));

	int num;
	num = coll2.erase(5);
	cout << num << " element(s) removed" << endl;

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main_set()
{
	typedef set<int, greater<int> >IntSet;  //降序

	IntSet coll1;

	coll1.insert(4);
	coll1.insert(3);
	coll1.insert(5);
	coll1.insert(1);
	coll1.insert(6);
	coll1.insert(2);
	coll1.insert(5);

	IntSet::iterator pos;
	for (pos = coll1.begin(); pos != coll1.end(); ++pos) {
		cout << *pos << ' ';
	}
	cout << endl;

	pair<IntSet::iterator, bool> status = coll1.insert(4);
	if (status.second) {
		cout << "4 inserted as element " << 
			distance(coll1.begin(), status.first) + 1 << endl;
	}
	else{
		cout << "4 already exists" << endl;
	}

	set<int> coll2(coll1.begin(), coll1.end());  //升序

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	coll2.erase(coll2.begin(), coll2.find(3));

	int num;
	num = coll2.erase(5);
	cout << num << " element(s) removed" << endl;

	copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


void f()
{
	set<double> c;
	if (c.insert(3.3).second) {
		cout << "3.3 inserted " << endl;
	}
	else{
		cout << "3.3 already exists" << endl;
	}
	if (c.insert(3.3).second) {
		cout << "3.3 inserted " << endl;
	}
	else {
		cout << "3.3 already exists" << endl;
	}
}

void f1()
{
	set<float> c;
	pair<set<float>::iterator, bool> status;
	status = c.insert(10.01);

	if (status.second) {
		cout << "inserted 10.01 as element";
	}
	else {
		cout << "already exists as element";
	}
	cout << distance(c.begin(), status.first) + 1 << endl;
}

//set要删除“与某值相等”的元素，只需调用erase
void f2()
{
	set<int> coll;
	coll.insert(10);
	coll.erase(10);  //返回非0即1
}

//Multisets内含重复元素，不能使用erase()来删除这些重复元素中的第一个
void f3()
{
	multiset<int> coll;
	coll.insert(10);
	coll.insert(10);
	multiset<int>::iterator pos;
	pos = coll.find(10);
	if (pos!= coll.end()) {
		coll.erase(pos);
	}
}


int main03()
{
	f();
	f1();
	f2();
	f3();
	return 0;
}

int main02()
{
	set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_range(3): " << *c.equal_range(3).first
		<< " " << *c.equal_range(3).second << endl;
	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_range(5): " << *c.equal_range(5).first
		<< " " << *c.equal_range(5).second << endl;
}


int main01()
{
	typedef std::set<int> IntSet;
	IntSet coll;

	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);
	coll.insert(6);
	coll.insert(2);

	IntSet::const_iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}