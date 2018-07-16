#include <iostream>
#include <list>
#include <string>
#include <deque>
#include <algorithm>
#include <cstdlib>  //abs()
using namespace std;

class Person {
public:
	string firstname() const{}
	string lastname() const{}
};

bool personSortCriterion(const Person& p1, const Person& p2)
{
	return p1.lastname() < p2.lastname() ||(!(p2.lastname() < p1.lastname()) &&p1.firstname() < p2.firstname());
}
int main()
{
	deque<Person> coll;
	sort(coll.begin(), coll.end(), personSortCriterion);
	return 0;
}
















bool isPrime(int number)
{
	number = abs(number);

	if (number == 0 || number == 1) {
		return true;
	}

	int divisor;
	for (divisor = number / 2; number%divisor != 0; --divisor) {
		;
	}
	return divisor == 1;
}

int main01()
{
	list<int> coll;

	for (int i = 24; i <= 30; i++) {
		coll.push_back(i);
	}
	list<int>::iterator pos;
	pos = find_if(coll.begin(), coll.end(), isPrime);
	if (pos != coll.end()) {
		cout << *pos << "is first prime number found" << endl;
	}
	else{
		cout << "no prime number found" << endl;
	}
}
