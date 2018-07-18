#include "algostuff.hpp"
#include <cstdlib>
using namespace std;

int myrand()
{
	return rand() % 100;
}

//赋予新数值
int main()
{
	list<int> coll;
	generate_n(back_inserter(coll), 5,rand);
	PRINT_ELEMENTS(coll);

	generate(coll.begin(), coll.end(), myrand);
	PRINT_ELEMENTS(coll);
}