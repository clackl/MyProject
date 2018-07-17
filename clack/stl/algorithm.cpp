#include<iostream>
#include<algorithm>    //max swap
using namespace std;

bool int_ptr_less(int *a, int*b) {
	return *a < *b;
}

int main01()   //max
{
	int x = 15;
	int y = 42;
	int*px = &x;
	int*py = &y;
	int *pmax;
	//const T& max ( const T& a, const T& b, Compare comp );
	pmax = max(px, py, int_ptr_less);
	 cout<< *pmax << endl;
}


//template <class T> void swap ( T& a, T& b );
class MyContainer {
	private:
		int *elems;
		int numelems;
	public:
		//swap的实现
		void swap(MyContainer& x) {
			std::swap(elems, x.elems);
			std::swap(numelems, x.numelems);
		}
		//重载全局swap
		inline void swap(MyContainer& c1, MyContainer& c2)
		{
			c1.swap(c2);
		}
};
