template<class T>
class CountedPtr {
private:
	T * ptr;
	long* count;
public:
	//ʹ�ô��ڵ�ָ���ʼ��ָ�룬Ҫ���Ǹ�ָ��p��һ������һ��new��ֵ
	explicit CountedPtr(T* p = 0) :ptr(p), count(new long(1)) {
	}
	//����ָ��
	CountedPtr(const CountedPtr<T>& p) throw() :ptr(p.ptr), count(p.count) {
		++*count;
	}
	//��������
	~CountedPtr() throw() {
		dispose();
	}
	//������ɵģ������µļ�ֵ
	CountedPtr<T>& operator = (const CountedPtr<T>& p) throw() {
		if (this != &p) {
			dispose();
			ptr = p.ptr;
			count = p.count;
			++*count;
		}
		return *this;
	}

	T& operator*() const throw() {
		return *ptr;
	}
	T* operator-> () const throw() {
		return ptr;
	}
private:
	void dispose() {
		if (--*count == 0) {
			delete count;
			delete ptr;
		}
	}
};