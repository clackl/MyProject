#include <cstdio>
#include <iostream>
#include <memory>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//template <class T>
//class MyClass
//{
//public:
//	template <class X>
//	void assign(const MyClass<X>& x) { value = x.value; }
//	//typename T::SubType * ptr; //T::SubType是一个类型。ptr就是指向T::SubType的指针
//private:
//	T value;
//};
//void f()
//{
//	MyClass<double> d;
//	MyClass<int> i;
//	d.assign(d);
//	//d.assign(i);  //err i 是 int型，而d要求double
//	d.assign(i); //添加template <class X>后
//}

//template <class T>
//class MyClass
//{
//public: 
//	//具有隐式类型转换的复制构造函数
//	//不隐藏隐式复制构造函数
//	template <class U>
//	MyClass(const MyClass<U>& x);
//	//...
//};
//void f()
//{
//	MyClass<double> xd;
//	MyClass<double> xd2(xd); //通过拷贝构造函数
//	MyClass<int> xi(xd);   //模板构造
//	//...
//}

//int i1; //不明确的值
//int i2 = int();//初始化为0
//template<class T>
//void f() {
//	T x = T(); //x保证被初始化为零
//}

//class Error;
//void f() {
//	if (exception - condition) {
//		throw Error(); //创建类错误对象，并将其作为异常抛出
//	}
//}
//int main()
//{
//	try {
//		//...
//		f();
//		//...
//	}
//	catch (const Error&) {
//		//... //句柄异常
//	}
//	// ...
//}

//class Stack {
//public:
//	Stack(int size) {}
//	Stack(const char *p) {}
//};
//int f() { 
//	Stack s1(10);  //ok  为Stack预分配10字节大小的内存
//	Stack s2 = 10;  //ok  为Stack预分配10字节大小的内存
//	Stack s3;       //err 没有默认构造函数
//	s3 = 10;        //err 存在默认构造函数是ok的
//	Stack s4("ada");  //ok  
//	Stack s5 = "asfas"; //ok  调用Strack(const char *p)
//	Stack s6 = 'c';      //ok 调用的是Stack(int size)，且size等于'c'的ASCII码
//	s1 = 2;           //ok  为stack预分配两个字节大小的内存
//	s2 = 3;          //ok  为stack预分配两个字节大小的内存
//	s1 = s2;          //ok  编译没有问题，free释放内存指针可能会出错
//}

//C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的
//class Stack {
//public:
//	explicit Stack(int size){}
//	Stack(const char *p) {}
//};
//int f() { //全部ok
//	Stack s1(10); //ok
//	Stack s2 = 10; //err explicit取消了隐式转换
//	Stack s3;   // err 没有默认构造函数
//	s3 = 10;    //err 有默认构造函数也err
//	Stack s4("ada");   //ok
//	Stack s5 = "asfas"; //ok
//	Stack s6 = 'c';   //err 
//	s1 = 2;  //err
//	s2 = 3;  //err
//	s1 = s2;  //err
//}

//void fun()
//{
//	float x = 1.231;
//	cout << static_cast<int>(x)<<endl;   // 1
//	string s =static_cast<string>("hello");
//	
//}

//class MyClass
//{
//	static const int num = 100;  //对整数型常数静态成员直接赋予初值，初始化后，便可用于class中
//	int elems[num];
//};
//const int MyClass::num;//必须为class之中声明的常数静态成员，定义一个空间
//
//
//void f()
//{
//	MyClass *ptr = new MyClass;
//	try {
//
//	}
//	catch (...) {
//		delete ptr;   //代码复杂累赘
//		throw;
//	}
//	delete ptr;
//}
////auto_ptr指针是它所指对象的拥有者，当对象拥有者auto_ptr被摧毁时，对象也会摧毁。
////auto_ptr要求对象只能有一个拥有者。
//void f()
//{
//	std::auto_ptr<MyClass> ptr(new MyClass);   //memory
//	//....    不需要delete
//}
////auto_ptr不允许使用一般指针惯用的赋值初始化方式。必须直接使用数值完成初始化
//auto_ptr<MyClass> ptr1(new MyClass); //ok
////auto_ptr<MyClass> ptr2 = new MyClass; //err
//
////由于auto_ptr会删除其所指对象，所以这个对象绝对不能同时被其他对象拥有
////绝不应该出现多个auto_ptr同时拥有一个对象的情况，如果以同一个对象为初值，将两个auto_ptr初始化，就会出现这种情况
//


//ios

//int f()  //copyfmt 复制cout的输出格式  //*******10
//{
//	ofstream filestr;
//	filestr.open("test.txt");
//
//	cout.fill('*');
//  //fill： 填充字符串
//	cout.width(10);
//	filestr.copyfmt(cout);
//
//	cout << 40;
//	filestr << 40;
//}

//int f_exceptions()  //exceptions
//{
//	ifstream file;
//	file.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
//	//eofbit 在输入流上执行提取操作时到达的文件结束
//	//failbit 最后一个输入操作失败了，因为与操作本身的内部逻辑相关的错误
//	//badbit 由于在流缓冲区上的输入/输出操作失败而导致的错误。
//	//goodbit 没有错误
//	try {
//		file.open("test.txt");
//		while (!file.eof()) file.get();
//	}
//	catch (ifstream::failure e) {
//		cout << "Exception opening/reading file";
//	}
//
//	file.close();
//}

//int f()
//{
//	ifstream is;
//	is.open("test.txt");
//	if (!is)  //ios::operator!
//		cerr << "Error opening 'test.txt'\n";
//	return 0;
//}

//int f()
//{
//	streambuf *psbuf;
//	ofstream filestr;
//	filestr.open("home/caoliang/test.txt");
//
//	psbuf = filestr.rdbuf();
//	cout.rdbuf(psbuf);
//
//	cout << "This is written to the file";
//
//	filestr.close();
//	return 0;
//}

//int f()   //rdstate 返回流的当前内部错误状态标志 //setstate 设置错误状态标志
//{
//	ifstream is;
//	is.open("test1.txt");
//	if ((is.rdstate() & ifstream::failbit) != 0)
//		cerr << "Error opening 'test.txt'\n";
//	return 0;
//}

//int f() //tie 获取/设置相关的流
//{
//	ostream *prevstr;
//	ofstream ofs;
//	ofs.open("test.txt");
//
//	cout << "tie example:" << endl;
//
//	*cin.tie() << "This is inserted into cout";
//	prevstr = cin.tie(&ofs);
//	*cin.tie() << "This is inserted into the file";
//	cin.tie(prevstr);
//
//	ofs.close();
//	return 0;
//}

//istream

//istream::get 
//int get();   //从流中提取一个字符并返回它的值（c款待一个整数）。
//istream& get(char& c);  //从流中提取一个字符并将其存储在c中
//从流中提取字符，并将它们作为c字符串存储到数组中，
//从s开头的字符被提取出来，直到找到（n-1）字符，或者找到了de限制性字符'n'。
//如果在输入序列中到达文件的末尾，或者在输入操作期间发生错误，提取也会停止。
//如果找到了de限制性字符，它就不会从输入序列中提取出来，并且作为下一个字符被提取出来。
//如果您想要提取（并丢弃）这个字符，请使用getline。结束的空字符表示结束
//istream& get(char* s, streamsize n);  
//和上面一样，除了这个限制字符是指定的不可消除的m而不是“n”。
//istream& get(char* s, streamsize n, char delim);
//从流中提取字符，并将它们插入到流缓冲中，直到找到de限制性字符'n'或结束文件为止。
//如果在由流或由sb控制的输出序列控制的输入序列中发生错误，则提取也会停止。
//istream& get(streambuf& sb);
//和上面一样，除了这个限制字符是指定的不可消除的m而不是“n”
//istream& get(streambuf& sb, char delim);
//通过调用成员函数gcount，可以获得以前输入操作中读取的字符数。
//c: 一个char变量来存储提取的字符
//s: 一个指向数组字符数组的指针，其中字符串被存储为c字符串
//n:存储的最大字符数（包括ternimnull null字符）。
//delim : 划界字符。当这个字符被读取时，提取成功字符的操作就停止了。
//这个参数是可选的，如果没有指定函数考虑'n'（换行字符）作为限定字符。
//sb : 输出流缓冲（类streambuf类或其派生类的对象）。

//int f()    //get(char* s, streamsize n);  
//{
//	char c, str[256];
//	ifstream is;
//	cout << "Enter the name of an existing text file: ";
//	cin.get(str, 256);
//	is.open(str);        // open file
//	while (is.good())     // loop while extraction from file is possible
//	{
//		c = is.get();       // get character from file
//		cout << c;
//	}
//	is.close();           // close file
//	return 0;
//}


//int f()    //get(char* s, streamsize n);  
//{
//	int length;
//	std::string st = "Enter the name of an existing text file:";
//	std::istringstream stream(st);
//	int i = 0;
//	char array[20] = { 0 };
//	while (stream.get(array, 20, ' '))
//	{
//		//获取当前位置
//		length = stream.tellg();
//
//		std::cout << array << std::endl;
//
//		//跳过逗号（,）
//		stream.seekg(length + 1, std::ios::beg);
//	}
//
//	return 0;
//}


//istream& getline(char* s, streamsize n);
//istream& getline(char* s, streamsize n, char delim);
//int f()  
//{
//	char name[256], title[256];
//	cout << "Enter your name:\n";
//	cin.getline(name, 256,',');
//	cout << "Enter your favourite movie:\n";
//	cin.getline(title, 256,',');
//	cout << name << "'s favourite movie is " << title<<endl;
//	return 0;
//}

//int f()  // istream ignore
//{
//	char first, last;
//	cout << "Enter your first and last names: ";
//	first = cin.get();
//	cin.ignore(256, ' ');
//	last = cin.get();
//	cout << "Your initials are " << first << last<<endl;
//	return 0;
//}

//int f()  //operator>>
//{
//	int n;
//	char str[10];
//	cout << "Enter a number: ";
//	cin >> n;
//	cout << "You have entered: " << n << endl;
//	cout << "Enter a hexadecimal number: ";
//	cin >> hex >> n;            // manipulator
//	cout << "Its decimal equivalent is: " << n << endl;
//	cout << "Enter a word: ";
//	cin.width(10);        // limit width
//	cin >> str;
//	cout << "The first 9 chars of your word are: " << str << endl;
//	return 0;
//}

//int f()  //setiosflags  设置格式标志
//{
//	cout << hex << setiosflags(ios_base::showbase | ios_base::uppercase);
//	cout << 100 << endl;
//	return 0;
//}

//int f()  //int peek ( ); 读取并返回下一个字符
//{
//	char c;
//	int n;
//	char str[256];
//	cout << "Enter a number or a word: ";
//	c = cin.peek();
//	if ((c >= '0') && (c <= '9'))
//	{
//		cin >> n;
//		cout << "You have entered number " << n << endl;
//	}
//	else
//	{
//		cin >> str;
//		cout << " You have entered word " << str << endl;
//	}
//	return 0;
//}

//int f()  //putback 将指针移到之前读取的字符的位置
//{
//	char c;
//	int n;
//	char str[256];
//	cout << "Enter a number or a word: ";
//	c = cin.get();  //123a
//	if ((c >= '0') && (c <= '9'))
//	{
//		//cin.putback(c);  //注释后结果 23
//		cin.putback(c);  //123
//		cin >> n;
//		cout << "You have entered number " << n << endl;
//	}
//	else
//	{
//		cin.putback(c);
//		cin >> str;
//		cout << " You have entered word " << str << endl;
//	}
//	return 0;
//}

//int f()   //read ( char* s, streamsize n );读取n个字符的数据块，并将其存储在由s指向的数组中。
//{
//	int length;
//	char * buffer;
//	ifstream is;
//	is.open("test.txt", ios::binary);  //binary 二进制
//	// get length of file:
//	is.seekg(0, ios::end);
//	length = is.tellg();    //tellg 返回get指针所在位置
//	cout<<"length"<< length << endl;
//	is.seekg(0, ios::beg);
//	// allocate memory:
//	buffer = new char[length];
//	// read data as a block:
//	is.read(buffer, length);
//	is.close();
//	cout.write(buffer, length);
//	delete[] buffer;
//	return 0;
//}

//int f()  //int sync()  同步输入缓冲区和字符的来源 缓冲中的未读字符被丢弃  linux测试无效
//{
//	ifstream r("test.txt");
//	char a = r.get();
//	cout << a << endl;
//	r.sync();
//	cout << char(r.get()) << endl;
//	return 0;
//}

//int f()  //unget  将内部的get指针递减一个
//{
//	char c;
//	int n;
//	char str[256];
//	cout << "Enter a number or a word: ";
//	c = cin.get();
//	if ((c >= '0') && (c <= '9'))
//	{
//		cin.unget();
//		cin >> n;
//		cout << "You have entered number " << n << endl;
//	}
//	else
//	{
//		cin.unget();
//		cin >> str;
//		cout << " You have entered word " << str << endl;
//	}
//	return 0;
//}

//ostream

//int f()  //ostream& flush ( ); 刷新输出流缓冲区 防止数据丢失 
//{
//	ofstream outfile("test.txt");
//	for (int n = 0; n<100; n++)
//	{
//		outfile << n;
//		outfile.flush();
//	}
//	outfile.close();
//	return 0;
//}

//int f()  //put 
//{
//	char ch;
//	ofstream outfile("test.txt");
//
//	do {
//		ch = cin.get();
//		outfile.put(ch);
//	} while (ch != '.');
//
//	return 0;
//}

//seekp 设置放置指针的位置  tellp  得到放指针位置 write
//int f()  
//{
//	long pos;
//	ofstream outfile;
//	outfile.open("test.txt");
//	outfile.write("This is an apple", 16);
//	pos = outfile.tellp();
//	pos = outfile.tellp();
//	outfile.seekp(pos - 7);
//	outfile.write(" sam", 4);
//	outfile.close();
//	return 0;
//}

//streambuf

//int f()  //streamsize in_avail ( )  获取可读的字符数  //linux无效
//{
//	streamsize size;
//	char ch;
//	streambuf * pbuf;
//	pbuf = cin.rdbuf();
//	cout << "Please enter some characters: ";
//	cin >> ch;
//	size = pbuf->in_avail();
//	cout << "The first character you entered is: " << ch << endl;
//	cout << size << " additional characters in input buffer" << endl;
//	return 0;
//}

//ifstream  ofstream

//int f()  //filebuf* rdbuf ( ) const;
//{
//	filebuf *pbuf;
//	ifstream filestr;
//	long size;
//	char * buffer;
//	filestr.open("test.txt");
//	// get pointer to associated buffer object
//	//获取指向相关联的缓冲区对象的指针
//	pbuf = filestr.rdbuf();
//	// get file size using buffer's members
//	//使用缓冲区的成员获取文件大小
//	size = pbuf->pubseekoff(0, ios::end, ios::in);
//	pbuf->pubseekpos(0, ios::in);
//	// allocate memory to contain file data
//	//分配内存以包含文件数据
//	buffer = new char[size];
//	// get file data  
//	pbuf->sgetn(buffer, size);
//	filestr.close();
//	// write content to stdout
//	cout.write(buffer, size);
//	return 0;
//}


//istringstream
//int f()
//{
//	int val, n;
//	istringstream iss;
//	string strvalues = "32 240 2 1450";
//	iss.str(strvalues);
//	for (n = 0; n<4; n++)
//	{
//		iss >> val;
//		cout << val + 1 << endl;
//	}
//}





int main()
{
	f();
    printf("hello from clack!\n");
    return 0;
}