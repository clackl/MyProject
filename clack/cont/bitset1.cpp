#include <iostream>
#include <bitset>
#include <string>
#include <limits>
using namespace std;


int main()
{
	cout << "267 as binary short: "
		<< bitset<numeric_limits<unsigned short>::digits>(267) << endl;

	cout << "267 as binary long: "
		<< bitset<numeric_limits<unsigned long>::digits>(267) << endl;

	cout << "10,000,000 with 24 bits: "
		<< bitset<24>(1e7) << endl;

	cout << "\"1000101011\" as number: " << bitset<100>(string("1000101011")).to_ulong() << endl;

}


int main01()
{
	enum Color {
		red, yellow, green, blue, white, black,
		numColors
	};

	bitset<numColors> usedColors;

	usedColors.set(red);
	usedColors.set(blue);

	cout << "bitfiled of used colors: " << usedColors << endl;
	cout << "number of used colors: " << usedColors.count() << endl;
	cout << "bitfield of unused colors: " << ~usedColors << endl;

	if (usedColors.any()) {
		for (int c = 0; c < numColors; ++c) {
			if (usedColors[(Color)c]) {

			}
		}
	}


}