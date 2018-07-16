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
//	//typename T::SubType * ptr; //T::SubType��һ�����͡�ptr����ָ��T::SubType��ָ��
//private:
//	T value;
//};
//void f()
//{
//	MyClass<double> d;
//	MyClass<int> i;
//	d.assign(d);
//	//d.assign(i);  //err i �� int�ͣ���dҪ��double
//	d.assign(i); //���template <class X>��
//}

//template <class T>
//class MyClass
//{
//public: 
//	//������ʽ����ת���ĸ��ƹ��캯��
//	//��������ʽ���ƹ��캯��
//	template <class U>
//	MyClass(const MyClass<U>& x);
//	//...
//};
//void f()
//{
//	MyClass<double> xd;
//	MyClass<double> xd2(xd); //ͨ���������캯��
//	MyClass<int> xi(xd);   //ģ�幹��
//	//...
//}

//int i1; //����ȷ��ֵ
//int i2 = int();//��ʼ��Ϊ0
//template<class T>
//void f() {
//	T x = T(); //x��֤����ʼ��Ϊ��
//}

//class Error;
//void f() {
//	if (exception - condition) {
//		throw Error(); //�����������󣬲�������Ϊ�쳣�׳�
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
//		//... //����쳣
//	}
//	// ...
//}

//class Stack {
//public:
//	Stack(int size) {}
//	Stack(const char *p) {}
//};
//int f() { 
//	Stack s1(10);  //ok  ΪStackԤ����10�ֽڴ�С���ڴ�
//	Stack s2 = 10;  //ok  ΪStackԤ����10�ֽڴ�С���ڴ�
//	Stack s3;       //err û��Ĭ�Ϲ��캯��
//	s3 = 10;        //err ����Ĭ�Ϲ��캯����ok��
//	Stack s4("ada");  //ok  
//	Stack s5 = "asfas"; //ok  ����Strack(const char *p)
//	Stack s6 = 'c';      //ok ���õ���Stack(int size)����size����'c'��ASCII��
//	s1 = 2;           //ok  ΪstackԤ���������ֽڴ�С���ڴ�
//	s2 = 3;          //ok  ΪstackԤ���������ֽڴ�С���ڴ�
//	s1 = s2;          //ok  ����û�����⣬free�ͷ��ڴ�ָ����ܻ����
//}

//C++�е�explicit�ؼ���ֻ����������ֻ��һ���������๹�캯��, ���������Ǳ����ù��캯������ʾ��, ������ʽ��
//class Stack {
//public:
//	explicit Stack(int size){}
//	Stack(const char *p) {}
//};
//int f() { //ȫ��ok
//	Stack s1(10); //ok
//	Stack s2 = 10; //err explicitȡ������ʽת��
//	Stack s3;   // err û��Ĭ�Ϲ��캯��
//	s3 = 10;    //err ��Ĭ�Ϲ��캯��Ҳerr
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
//	static const int num = 100;  //�������ͳ�����̬��Աֱ�Ӹ����ֵ����ʼ���󣬱������class��
//	int elems[num];
//};
//const int MyClass::num;//����Ϊclass֮�������ĳ�����̬��Ա������һ���ռ�
//
//
//void f()
//{
//	MyClass *ptr = new MyClass;
//	try {
//
//	}
//	catch (...) {
//		delete ptr;   //���븴����׸
//		throw;
//	}
//	delete ptr;
//}
////auto_ptrָ��������ָ�����ӵ���ߣ�������ӵ����auto_ptr���ݻ�ʱ������Ҳ��ݻ١�
////auto_ptrҪ�����ֻ����һ��ӵ���ߡ�
//void f()
//{
//	std::auto_ptr<MyClass> ptr(new MyClass);   //memory
//	//....    ����Ҫdelete
//}
////auto_ptr������ʹ��һ��ָ����õĸ�ֵ��ʼ����ʽ������ֱ��ʹ����ֵ��ɳ�ʼ��
//auto_ptr<MyClass> ptr1(new MyClass); //ok
////auto_ptr<MyClass> ptr2 = new MyClass; //err
//
////����auto_ptr��ɾ������ָ�����������������Բ���ͬʱ����������ӵ��
////����Ӧ�ó��ֶ��auto_ptrͬʱӵ��һ�����������������ͬһ������Ϊ��ֵ��������auto_ptr��ʼ�����ͻ�����������
//


//ios

//int f()  //copyfmt ����cout�������ʽ  //*******10
//{
//	ofstream filestr;
//	filestr.open("test.txt");
//
//	cout.fill('*');
//  //fill�� ����ַ���
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
//	//eofbit ����������ִ����ȡ����ʱ������ļ�����
//	//failbit ���һ���������ʧ���ˣ���Ϊ�����������ڲ��߼���صĴ���
//	//badbit ���������������ϵ�����/�������ʧ�ܶ����µĴ���
//	//goodbit û�д���
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

//int f()   //rdstate �������ĵ�ǰ�ڲ�����״̬��־ //setstate ���ô���״̬��־
//{
//	ifstream is;
//	is.open("test1.txt");
//	if ((is.rdstate() & ifstream::failbit) != 0)
//		cerr << "Error opening 'test.txt'\n";
//	return 0;
//}

//int f() //tie ��ȡ/������ص���
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
//int get();   //��������ȡһ���ַ�����������ֵ��c���һ����������
//istream& get(char& c);  //��������ȡһ���ַ�������洢��c��
//��������ȡ�ַ�������������Ϊc�ַ����洢�������У�
//��s��ͷ���ַ�����ȡ������ֱ���ҵ���n-1���ַ��������ҵ���de�������ַ�'n'��
//��������������е����ļ���ĩβ����������������ڼ䷢��������ȡҲ��ֹͣ��
//����ҵ���de�������ַ������Ͳ����������������ȡ������������Ϊ��һ���ַ�����ȡ������
//�������Ҫ��ȡ��������������ַ�����ʹ��getline�������Ŀ��ַ���ʾ����
//istream& get(char* s, streamsize n);  
//������һ����������������ַ���ָ���Ĳ���������m�����ǡ�n����
//istream& get(char* s, streamsize n, char delim);
//��������ȡ�ַ����������ǲ��뵽�������У�ֱ���ҵ�de�������ַ�'n'������ļ�Ϊֹ��
//�������������sb���Ƶ�������п��Ƶ����������з�����������ȡҲ��ֹͣ��
//istream& get(streambuf& sb);
//������һ����������������ַ���ָ���Ĳ���������m�����ǡ�n��
//istream& get(streambuf& sb, char delim);
//ͨ�����ó�Ա����gcount�����Ի����ǰ��������ж�ȡ���ַ�����
//c: һ��char�������洢��ȡ���ַ�
//s: һ��ָ�������ַ������ָ�룬�����ַ������洢Ϊc�ַ���
//n:�洢������ַ���������ternimnull null�ַ�����
//delim : �����ַ���������ַ�����ȡʱ����ȡ�ɹ��ַ��Ĳ�����ֹͣ�ˡ�
//��������ǿ�ѡ�ģ����û��ָ����������'n'�������ַ�����Ϊ�޶��ַ���
//sb : ��������壨��streambuf�����������Ķ��󣩡�

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
//		//��ȡ��ǰλ��
//		length = stream.tellg();
//
//		std::cout << array << std::endl;
//
//		//�������ţ�,��
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

//int f()  //setiosflags  ���ø�ʽ��־
//{
//	cout << hex << setiosflags(ios_base::showbase | ios_base::uppercase);
//	cout << 100 << endl;
//	return 0;
//}

//int f()  //int peek ( ); ��ȡ��������һ���ַ�
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

//int f()  //putback ��ָ���Ƶ�֮ǰ��ȡ���ַ���λ��
//{
//	char c;
//	int n;
//	char str[256];
//	cout << "Enter a number or a word: ";
//	c = cin.get();  //123a
//	if ((c >= '0') && (c <= '9'))
//	{
//		//cin.putback(c);  //ע�ͺ��� 23
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

//int f()   //read ( char* s, streamsize n );��ȡn���ַ������ݿ飬������洢����sָ��������С�
//{
//	int length;
//	char * buffer;
//	ifstream is;
//	is.open("test.txt", ios::binary);  //binary ������
//	// get length of file:
//	is.seekg(0, ios::end);
//	length = is.tellg();    //tellg ����getָ������λ��
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

//int f()  //int sync()  ͬ�����뻺�������ַ�����Դ �����е�δ���ַ�������  linux������Ч
//{
//	ifstream r("test.txt");
//	char a = r.get();
//	cout << a << endl;
//	r.sync();
//	cout << char(r.get()) << endl;
//	return 0;
//}

//int f()  //unget  ���ڲ���getָ��ݼ�һ��
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

//int f()  //ostream& flush ( ); ˢ������������� ��ֹ���ݶ�ʧ 
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

//seekp ���÷���ָ���λ��  tellp  �õ���ָ��λ�� write
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

//int f()  //streamsize in_avail ( )  ��ȡ�ɶ����ַ���  //linux��Ч
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
//	//��ȡָ��������Ļ����������ָ��
//	pbuf = filestr.rdbuf();
//	// get file size using buffer's members
//	//ʹ�û������ĳ�Ա��ȡ�ļ���С
//	size = pbuf->pubseekoff(0, ios::end, ios::in);
//	pbuf->pubseekpos(0, ios::in);
//	// allocate memory to contain file data
//	//�����ڴ��԰����ļ�����
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