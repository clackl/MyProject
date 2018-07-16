template<class T>
class CountedPtr {
private:
	T * ptr;
	long* count;
public:
	//使用存在的指针初始化指针，要求那个指针p是一个返回一个new的值
	explicit CountedPtr(T* p = 0) :ptr(p), count(new long(1)) {
	}
	//拷贝指针
	CountedPtr(const CountedPtr<T>& p) throw() :ptr(p.ptr), count(p.count) {
		++*count;
	}
	//析构函数
	~CountedPtr() throw() {
		dispose();
	}
	//不分享旧的，分享新的价值
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