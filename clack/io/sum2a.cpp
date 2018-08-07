#include <iostream>
#include <cstdlib>
namespace MyLib2 {
	double readAndProcessSum(std::istream& strm) {
		double value, sum;
		sum = 0;
		while (strm >> value) {
			if(value==-1)
				break;
			sum += value;
		}

		if (!strm.eof()) {
			throw std::ios::failure("input error in readAndProcessSum()");
		}
		return sum;
	}
}

int sum2a()
{
	using namespace std;
	double sum;

	try {
		sum = MyLib2::readAndProcessSum(cin);
	}
	catch (const ios::failure& error) {
		cerr << "I/O exception: " << error.what() << endl;
		return EXIT_FAILURE;
	}
	catch (const exception& error) {
		cerr << "standard exception: " << error.what() << endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		cerr << "unknown exception" << endl;
		return EXIT_FAILURE;
	}
	cout << "sum: " << sum << endl;
	return 0;
}