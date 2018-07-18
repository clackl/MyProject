#ifndef ALGOSTUFF_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>

template <class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr = "")
{
	typename T::const_iterator pos;
	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		std::cout << *pos << ' ';
	}
	std::cout << std::endl;
}

template<class T>
inline void INSERT_ELEMENT(T& coll, int first, int last)
{
	for (int i = first; i <= last; ++i) {
		coll.insert(coll.end(), i);
	}
}

#endif ALGOSTUFF_HPP

