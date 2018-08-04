#include <iostream>
#include <valarray>
using namespace std;

template<class T>
void printValarray(const valarray<T>& va) 
{
	for (int i = 0; i < va.size(); ++i) {
		cout << va[i] << ' ';
	}
	cout << endl;
}

int main02()
{
	valarray<double> va(9);
	for (int i = 0; i < va.size(); ++i) {
		va[i] = i * 1.1;
	}
	printValarray(va);
	va *= 2.0;

	printValarray(va);

	valarray<double> vb(va + 10.0);
	printValarray(vb);

	valarray<double> vc;
	vc = sqrt(va) + vb / 2.0 - 1.0;

	printValarray(vc);
}

int main01()
{
	valarray<double> va1(10), va2(10);
	for (int i = 0; i < 10; ++i) {
		va1[i] = i * 1.1;
	}
	va2 = -1;
	printValarray(va1);
	printValarray(va2);

	cout << "min(): " << va1.min() << endl;
	cout << "max(): " << va1.max() << endl;
	cout << "sum(): " << va1.sum() << endl;

	va2 = va1;
	va1.resize(0);

	printValarray(va1);
	printValarray(va2);
}