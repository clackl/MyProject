#include <iostream>
#include <cstdlib>

namespace MyLib1 {
	double readAndProcessSum(std::istream& strm)
	{
		using std::ios;
		double value, sum;

		ios::iostate oldExceptions = strm.exceptions();
		strm.exceptions(ios::failbit | ios::badbit);
		try {
			sum = 0;
			while (strm >> value) {
				if(value==-1)
					break;
				sum += value;
			}
		}
		catch (...) {
			if (!strm.eof()) {
				strm.exceptions(oldExceptions);
				throw;
			}
		}
		strm.exceptions(oldExceptions);
		return sum;
	}
}

int sum1a()
{
	using namespace std;
	double sum;

	try {
		sum = MyLib1::readAndProcessSum(cin);
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