#include <iostream>
#include "outbuf.hpp"

int outbuf1()
{
	outbuf ob;
	std::ostream out(&ob);
	out << "31 hexadecimal: " << std::hex << 31 << std::endl;
}