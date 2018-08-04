#include <iostream>
#include <valarray>
using namespace std;

template<class T>
void printValarray(const valarray<T>& va,int num)
{
	for (int i = 0; i < va.size()/num; ++i) {
		for (int j = 0; j < num; ++j) {
			cout << va[i*num+j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	valarray<double> va(12);
	for (int i = 0; i < 12; ++i) {
		va[i] = i;
	}
	printValarray(va, 3);
	va[slice(0, 4, 3)] = pow(valarray<double>(va[slice(1, 4, 3)]),
		valarray<double>(va[slice(2, 4, 3)]));
	printValarray(va, 3);
	valarray<double> vb(va[slice(2, 4, 0)]);
	va[slice(2, 4, 3)] *= vb;
	printValarray(va, 3);
	printValarray(sqrt(valarray<double>(va[slice(3, 3, 1)])), 3);
	va[slice(2, 4, 3)] = valarray<double>(va[slice(2, 4, 3)])*2.0;
	printValarray(va, 3);
}