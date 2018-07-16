#include<iostream>
#include<memory>
using namespace std;


template <class T>
ostream& operator<< (ostream& strm, const auto_ptr<T>& p)
{
	if (p.get() == NULL) strm << "NULL";
	else strm << *p;
	return strm;
}

int main01()//auto_ptrsת��ӵ��Ȩ����Ϊ
{
	auto_ptr<int> p(new int(42));
	//auto_ptr<int> p = new int (42);   //err
	//p =new int(42) //err
	auto_ptr<int> q;

	cout << "afte initialzation:" << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;

	q = p;
	cout << "after assigning auto pointes: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;

	*q += 13;
	p = q;
	cout << "after change and reassignment:" << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
}

//const auto_ptr����
int main()
{
	const auto_ptr<int> p(new int(42));
	const auto_ptr<int> q(new int(0));
	const auto_ptr<int> r;

	cout << "afte initialzation:" << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << q << endl;

	*q = *p;
	//*r = *p;  err
	*p = -77;

	cout << "after assigning values: " << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "r: " << q << endl;

	//q = p;  err
	//r = p;  err

}


//auto_ptr��ȷ��˵��  p80
namespace auto_ptr {
	//����������֧�ָ�������ҵ
	template <class Y> struct auto_ptr_ref {};

	template<class T>
	class auto_ptr {
	public:
		//ֵ����������
		typedef T element_type;

		//���캯��
		explicit auto_ptr��T* ptr = 0�� throw();

		//�������캯������ʽ����ת����
		//�Ǻ㶨����
		auto_ptr& operator  = (auto_ptr&) throw();
		template<class U>
		auto_ptr& operator = (auto_ptr<U>&) throw();

		//��������
		~auto_ptr() throw();

		//ֵ����
		T* get() const throw();
		T& operator*() cosnt throw();
		T* operator->() const throw();

		//�ͷ�ӵ��Ȩ
		T* release() throw();

		//����ֵ
		void reset(T* ptr = 0) throw();

		//����ת������֧�ָ�������ҵ
	public:
		auto_ptr(auto_ptr_ref<T>) throw();
		auto_ptr& operator= (auto_ptr_ref<T> rhs) throw();
		template<class U> operator auto_ptr_ref<U>() throw();
		template<class U> operator auto_ptr<U>() throw();

	};
}