#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	const string delims(" \t,.;");
	string line;

	while (getline(cin, line)) {
		string::size_type begIdx, endIdx;
		begIdx = line.find_first_not_of(delims);

		while (begIdx != string::npos) {
			endIdx = line.find_first_of(delims, begIdx);
			if (endIdx == string::npos) {
				endIdx = line.length();
			}

			for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i) {
				cout << line[i];
			}
			cout << ' ';

			begIdx = line.find_first_not_of(delims, endIdx);
		}
		cout << endl;

	}
}



int main01(int argc,char* argv[])
{
	string filename, basename, extname, tmpname;
	const string suffix("tmp");

	for (int i = 1; i < argc; i++) {
		filename = argv[i];
		string::size_type idx = filename.find('.');
		if (idx == string::npos) {
			tmpname = filename + '.' + suffix;
		}
		else {
			basename = filename.substr(0, idx);
			extname = filename.substr(idx + 1);
			if (extname.empty()) {
				tmpname = filename;
				tmpname += suffix;
			}
			else if (extname == suffix) {
				tmpname = filename;
				tmpname.replace(idx + 1, string::npos, suffix);
			}
		}
		cout << filename << " =>" << tmpname << endl;
	}
}


