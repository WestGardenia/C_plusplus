#include<iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//		,_num(p._num)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			this->_name = p._name;
//			this->_num = p._num;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//public:
//	string _name = "张三";
//	int _num = 999;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name),
//		_num(num)
//	{
//		cout << "Student(const char* name, int num)" << endl;
//	}
//	Student(const Student& s)
//		:_num(s._num)
//		,Person(s)	// 这里可以直接把子类传给父类的拷贝构造。编译器会进行切片处理
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	void Print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "学号：" << _num << endl;
//		cout << "身份证号：" << Person::_num << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// 这里要想调用父类的重载运算符，就一定要确定作用域
//			// 否则父类和子类有相同的重载函数会造成重定义，而重定义会使得父类的operator=隐藏
//			// 这样再调用operatro=就是调用子类自己定义的，这样就会造成递归调用
//			Person::operator=(s);	// 把子类对象传给父类函数编译器会对对象进行切片——只传父类有的成员
//			_num = s._num;
//			cout << "Student& operator=(const Student& s)" << endl;
//		}
//	}
//	~Student()
//	{
//		// 子类的析构函数和父类的析构函数会构成隐藏
//		// 因为他们的函数名称会被编译器处理成destroy
//		// 同时，子类对象在析构的过程中，根据栈的特性，
//		//		父类构造->子类构造->子类析构->父类析构
//		// 所以子类析构不需要子类显示调用父类的析构函数
//		// 子类析构函数会自动调用父类的析构函数，这样才能保证先析构子类，再析构父类的顺序
//		//Person::~Person();
//		cout << "~Student()" << endl;
//	}
//public:
//	int _num = 111;
//};

// 1、继承类赋值规则
// 子类可以给父类赋值，包括值/指针/引用
// 但是父类不能给子类赋值，尤其不能直接传值
//
// 2、当父类和子类同时有同名成员时，子类成员会隐藏父类成员（重定义）
//		重定义和重载的区别：
//			重载：必须要是在同一作用域下，函数名相同，参数不同
//			重定义：在不同作用域下，有相同的函数名或者成员名
//		编译器会先在子类中寻找，再到父类中寻找
// 如果确实要访问父类的同名成员，那就要指定作用域
//
// 3、如何设计一个不能被继承的类
//	方法：构造函数私有——子类要进行构造就一定要调用父类的构造函数，但是父类构造函数私有就无法调用
// 
// 4、友元成员无法继承
// 5、静态成员可以继承，但是继承下来的是同一块空间，即给子类的静态成员进行操作也会直接改变父类的静态成员
// 
// 继承的本质是复用
// 多继承就会造成菱形继承
// 菱形继承则会产生数据的冗余和二义性——某一子类同时有两种相同的父类
// 
// 面试题：C++的缺陷：多继承会导致菱形继承
//			解决的方案：虚继承，加入virtual字段 
//	
// 
//int main()
//{
//	//Person p;
//	//Student s("Peter",1);
//	//s.Print();
//	//Student s1(s);
//	//Student s2 = s1;
//	//s2.Print();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B :virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :virtual public B, virtual public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	// 实际中，不到万不得已，不要用多继承
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 6;
//	return 0;
//}

// 继承和组合
// 继承
// 是一种白箱复用，父类对于子类基本是透明的，子类可能会破坏父类的封装
class A{};
class B :public A
{ };

// 组合
// 是一种黑箱复用，C对于D是不透明的，C可以保持它的封装
class C{};
class D
{
	C c;
};

// 组合的耦合度更低，而继承的类是一种高耦合
// 两种写法要视情况而定
// 组合一般是包含拥有的关系	（例如：车有轮胎）
// 继承一般是 是 的关系		（例如：老师是人）