#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstddef>
#include "print.cpp"
using namespace std;

//�Զ�����������
template<class T,std::size_t thesize>
class carray {
private:
	T v[thesize];
public:
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	iterator begin() { return v; }
	const_iterator begin() const { return v; }
	iterator end() { return v + thesize; }
	const_iterator end() const { return v + thesize; }

	reference operator[](std::size_t i) { return v[i]; }
	const_reference operator[](std::size_t i) const { return v[i]; }

	size_type size() const { return thesize; }
	size_type max_size() const { return thesize; }

	T* as_array() { return v; }

};

int main()
{
	carray<int, 10> a;
	for (unsigned i = 0; i < a.size(); ++i) {
		a[i] = i + 1;
	}
	PRINT_ELEMENTS(a);

	reverse(a.begin(), a.end() );
	PRINT_ELEMENTS(a);

	transform(a.begin(), a.end(), a.begin(), negate<int>());
	PRINT_ELEMENTS(a);
}


int main01()
{
	int coll[] = { 5,6,2,4,1,3 };

	//transform
	//��opӦ����[first1��last1]��Χ�ڵ�ÿ��Ԫ�أ�
	//����ÿ���������ص�ֵ�洢����result��ͷ�ķ�Χ�ڡ�
	// OutputIterator transform (InputIterator first1, InputIterator last1,
			//OutputIterator result, UnaryOperation op);
	
	//ʹ��[first1��last1]��Χ�е�ÿ��Ԫ����Ϊ��һ����������binary_op��
	//������first2��Ϊ�ڶ���������ʼ�ķ�Χ�е���Ӧ�������á�
	//ÿ�ε��÷��ص�ֵ���洢����result��ͷ�ķ�Χ�ڡ�
	// OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
			//InputIterator2 first2, OutputIterator result,BinaryOperation binary_op);

	transform(coll, coll + 6, coll, coll, multiplies<int>());
	sort(coll + 1, coll + 6);

	copy(coll, coll + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

}
