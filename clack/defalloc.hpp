namespace std {
	template<class T>
	class allocator {
	public:
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef T			value_type;

		template<class U>
		struct rebind {
			typedef allocator<U> other;
		};

		pointer address(reference value) const {
			return &value;
		}
		const_pointer address(const_reference value) const {
			return &value;
		}

		allocator() throw() {
		}
		allocator(const allocator&) throw() {
		}

		template<class U>
		allocator(const allocator<U>&) throw() {
		}

		~allocator() throw() {
		}

		size_type max_size() const throw() {
			return numeric_limits<size_t>::max() / sizeof(T);
		}

		pointer allocate(size_type num, allocator<void>::const_pointer hint = 0) {
			return (pointer)(::operator new(num * sizeof(T)));
		}

		void construct(pointer p, const T& value) {
			new((void*)p)T(value);
		}

		void destory(pointer p) {
			p->~T();
		}

		void deallocate(pointer p, size_type num) {
			::operator delete((void*)p);
		}

		template<class T1,class T2>
		bool operator == (const allocator<T1>&, const allocator<T2>&)throw() {
			return true;
		}

		template<class T1, class T2>
		bool operator != (const allocator<T1>&, const allocator<T2>&)throw() {
			return false;
		}
	};
}