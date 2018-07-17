#include <cctype> // for toupper
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "print.hpp"
#include "compose22.hpp"
using namespace std;

int main()
{
	string s("Internationalization");
	string sub("Nation");

	string::iterator pos;
	pos = search(s.begin(), s.end(), sub.begin(), sub.end(),
		compose_f_gx_hy(equal_to<int>(), ptr_fun(::toupper), ptr_fun(::toupper)));

	if (pos!= s.end()) {
		cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
	}
}