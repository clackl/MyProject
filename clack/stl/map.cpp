#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class RuntimeStringCmp {
public:
	enum cmp_mode{normal,nocase};
private:
	const cmp_mode mode;

	static bool nocase_compare(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
public:
	RuntimeStringCmp(cmp_mode m = normal) :mode(m) {
	}

	bool operator() (const string& s1, const string s2) const {
		if (mode == normal) {
			return s1 < s2;
		}
		else {
			return lexicographical_compare(s1.begin(), s1.end(),
				s2.begin(), s2.end(), nocase_compare);
		}
	}
};

typedef map<string, string, RuntimeStringCmp> StringStringMap;
void fillAndPrint(StringStringMap& coll);

int main()
{
	StringStringMap coll1;
	fillAndPrint(coll1);

	RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

	StringStringMap coll2(ignorecase);
	fillAndPrint(coll2);
}

void fillAndPrint(StringStringMap& coll)
{
	coll["Deutschland"] = "Germany";
	coll["deutsch"] = "Genman";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Jnternehmen"] = "enterprise";
	coll["unternehmen"] = "undertaker";
	coll["gehen"] = "walk";
	coll["Bestatter"] = "undertaker";

	StringStringMap::iterator pos;
	cout.setf(ios::left, ios::adjustfield);
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		cout << setw(15) << pos->first.c_str() << " " << pos->second << endl;
	}
	cout << endl;
}


template <class K,class V>
class value_equals {
private:
	V value;
public:
	value_equals(const V& v) :value(v) {}

	bool operator() (pair<const K, V> elem) {
		return elem.second == value;
	}
};


int main05()
{
	typedef map<float, float> FloatFloatMap;
	FloatFloatMap coll;
	FloatFloatMap::iterator pos;

	coll[1] = 7;
	coll[2] = 4;
	coll[3] = 2;
	coll[4] = 3;
	coll[5] = 6;
	coll[6] = 1;
	coll[7] = 3;

	pos = coll.find(3.0);
	if (pos != coll.end()) {
		cout << pos->first << ": " << pos->second << endl;
	}

	pos = find_if(coll.begin(), coll.end(), value_equals<float, float>(3.0));
	if (pos!= coll.end()) {
		cout << pos->first << ": " << pos->second << endl;
	}
}


//将Multimap当做字典
int main04()
{
	typedef multimap<string, string> StrStrMMap;
	StrStrMMap dict;

	dict.insert(make_pair("day", "Tag"));
	dict.insert(make_pair("strange", "fremd"));
	dict.insert(make_pair("car", "Auto"));
	dict.insert(make_pair("smart", "elegant"));
	dict.insert(make_pair("trait", "Merkmal"));
	dict.insert(make_pair("strange", "seltsam"));
	dict.insert(make_pair("smart", "raffiniert"));
	dict.insert(make_pair("smart", "klug"));
	dict.insert(make_pair("clever", "raffiniert"));

	StrStrMMap::iterator pos;
	cout.setf(ios::left, ios::adjustfield);
	cout << ' ' << setw(10) << "english " << "german " << endl;
	cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;
	for (pos = dict.begin(); pos != dict.end(); pos++) {
		cout << ' ' << setw(10) << pos->first.c_str() << pos->second << endl;
	}
	cout << endl;

	string word("smart");
	cout << word << ": " << endl;
	for (pos = dict.lower_bound(word); pos != dict.upper_bound(word); pos++) {
			cout << " " << pos->second << endl;
	}

	word = ("raffiniert");
	cout << word << ": " << endl;
	for (pos = dict.begin(); pos != dict.end(); pos++) {
		if (pos->second == word) {
			cout << " " << pos->first << endl;
		}
	}
	return 0;

}


//应用实例
int main03()
{
	typedef map<string, float> StringFloatMap;
	StringFloatMap stocks;

	stocks["BASF"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Daimler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 832.20;

	StringFloatMap::iterator pos;
	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
		cout << "stock: " << pos->first << "\t" << "price: " << pos->second << endl;
	}
	cout << endl;

	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
		pos->second *= 2;
	}

	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
		cout << "stock: " << pos->first << "\t" << "price: " << pos->second << endl;
	}
	cout << endl;

	//使用新的值替换旧的值
	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");

	for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
		cout << "stock: " << pos->first << "\t" << "price: " << pos->second << endl;
	}
	return 0;
}



int main02()
{
	typedef map<int, string> IntStringMMap;
	IntStringMMap coll;

	coll.insert(make_pair(3, "tagged"));
	coll.insert(make_pair(4, "a"));
	coll.insert(make_pair(1, "b"));

	
	IntStringMMap::iterator pos;

	for (pos = coll.begin(); pos != coll.end();pos++) {
		if (pos->first == 3) {
			coll.erase(pos);  //runtime err 
			//对pos所指元素实施erase()，会使pos不再成为一个有效coll迭代器
		}
	}
	//移除“迭代器所指元素”的正确做法
	for (pos = coll.begin(); pos != coll.end();) {
		if (pos->first == 3) {
			coll.erase(pos++);//pos++会将pos移到下一个元素，但返回其原始值得副本
		}
		else {
			++pos;
		}
	}
	coll[3] = coll[4]; //coll[key] 没有就会创建
	coll[7] = "fdsa";
}





int main01()
{
	typedef multimap<int, string> IntStringMMap;
	IntStringMMap coll;

	coll.insert(make_pair(3, "tagged"));
	coll.insert(make_pair(4, "a"));
	coll.insert(make_pair(1, "b"));
	

	//为避免隐形型别转换，有三种方式
	//1.利用value_type传递正确型别
	coll.insert(map<int, string>::value_type(10, "gjg"));
	//2.直接用pair<>
	//使用隐式型别转换
	coll.insert(pair<int, string>(12, "das"));
	//不使用隐式类型转换
	coll.insert(pair<int,const string>(12, "fads"));
	//运用make_pair()
	coll.insert(make_pair(2, "c"));

	IntStringMMap::iterator pos;
	pos = coll.find(12);
	if (pos != coll.end()) {
		coll.erase(pos);
	}


	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		cout << pos->second << ' ';
		//pos->first = 1;  err 
	}
	cout << endl;
}
