#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
	cout << boolalpha;   //bool变量会输出true和false

	cout << "max(short): " << numeric_limits<short>::max() << endl;
	cout << "max(int): " << numeric_limits<int>::max() << endl;
	cout << "max(long): " << numeric_limits<long>::max() << endl;
	cout << endl;

	cout << "max(float): " << numeric_limits<float>::max() << endl;
	cout << "max(double): " << numeric_limits<double>::max() << endl;
	cout << "max(long double): " << numeric_limits<long double>::max() << endl;
	cout << endl;

	cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
	cout << endl;

	cout << "is_signed(string): " << numeric_limits<string>::is_signed << endl;
	cout << endl;

	return 0;
}