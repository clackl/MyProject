#include <istream>
#include <limits>

template<class charT,class traits>
inline
std::basic_istream<charT, traits>& ignoreLine(std::basic_istream<charT, traits>& strm)
{
	strm.ignore(std::numeric_limits<int>::max(), strm.widen('\n'));
	return strm;
}

//忽略end-of-line之前的所有字符
//std::cin >> ignoreLine;