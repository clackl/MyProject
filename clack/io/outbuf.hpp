#include <streambuf>
#include <locale>
#include <cstdio>

class outbuf :public std::streambuf
{
protected:
	virtual int_type overflow(int_type c) {
		if (c != EOF) {
			c = std::toupper(c, getloc());

			if (putchar(c) == EOF) {
				return EOF;
			}
		}
		return c;
	}
public:
	outbuf(){}
};


//template<class charT, class traits = std::char_traits<charT> >
//class basic_outbuf :public std::basic_streambuf<charT, traits>
//{
//protected:
//	virtual int_type overflow(typename traits::int_type c) {
//		if (!traits::eq_int_type(c, traits::eof())) {
//			c = std::toupper(c, getloc());
//
//			if (putchar(c) == EOF) {
//				return traits::eof();
//			}
//		}
//		return traits::not_eof(c);
//	}
//};
//
//typedef basic_outbuf<char> outbuf;
//typedef basic_outbuf<wchar_t>woutbuf;