#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// 类的内部可以定义：
// 1、成员变量
// 2、成员方法
//class Person {
//	// 成员方法
//public:
//	// 表示公有方法
//	void showinfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//	// 成员变量（也叫类的属性）
//private:
//	// 表示私有属性
//	char _sex;
//	const char* _name;
//	int _age;
//};
//// 类中定义的内容可以分为公有和私有
//// 公有的属性或者方法由public访问限定符确定
//// 私有的属性或者方法由private访问限定符确定
//// 保护的属性或者方法由project访问限定符确定

//// 私有属性只针对调用这个类的函数有效，对于类内部定义的方法无效
//// 1、C语言中struct是用来定义结构体的
//// 2、C++中，兼容C的struct定义结构体的用法。同时，struct也可以用来定义类
//// 3、class默认的定义属性是私有的，而struct默认的是公有的
//
//int main()
//{
//	Person p1;
//	// 私有属性不可以直接访问
//	p1._name = "Peter";
//	p1._age = 20;
//	p1._sex = '1';
//	p1.showinfo();
//
//	return 0;
//}

// 1、声明和定义的区别？
//	声明是一种承诺，只是承诺要做的事，但还没有去做
//  定义就是把这个事情落实做好
//	只声明不定义会出现连接不上的报错

//class Stack {
//public:
//	// 1、成员函数有两种定义方法
//	void Push(int x)	// 1、在类里面定义
//	{
//		// ...
//	}
//	void Pop();	// 2、在类外面定义
//	void Destory()
//	{
//		// ...
//	}
//private:
//	// 2、成员变量
//	int* _a;
//	int _size;
//	int _capcity;	//	声明了成员变量
//
//};
//
//void Stack::Pop()
//{
//	// ...
//}
//
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//
//	// 计算类的大小
//	// 类实例化的对象中，只存储成员变量，不存储成员函数
//	//	原因：一个类实例化出N个对象，每个对象的成员变量都可以存储不同的值，但是调用的函数却是同一个
//	//		  如果每个对象都放成员函数，而这些成员函数却是一样的，那么就会浪费空间
//	// 因此计算类实例化出的对象的大小，只需要计算类的成员变量的大小之和即可（考虑内存对齐规则）
//	// 如果类中没有成员变量，那么他的大小就是1
//	//	原因：一定要有一定的空间在实例化时给他们占位，表示实例化出来的对象是存在的
//	cout << sizeof(s1) << endl;
//}


// 2、this指针
//class Date
//{
//public:
//	void Init(int year, int month, int day)	//void Init(Date* this, int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		// 这里的访问类属性，是通过隐含的this指针访问的，并不是属性存放在函数内的
//		// 这个this指针实际上指向了这个类的内部本身，使得成员函数可以访问成员变量
//		// 在传参时，编译器会自动将实例化的对象的指针作为参数传入函数
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	// 编译器处理版本：
//	//void Print(Date* this)
//	//{
//	//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2025, 1, 15);	//	d1.Init(&d1, 2025, 1, 15);
//	d1.Print();
//	return 0;
//}

// 1、this指针存放在进程地址空间的哪个区域
//		this指针是存在栈上的，this本质上是一个形参(vs下this指针是存放在ECX这个寄存器内的）
// 2、以下代码是否会正常运行
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	p->PrintA();	// 这里运行会崩溃，会发生空指针解引用
//	p->Show();		// 这里可以正常运行，因为并没有对于这个空对象的成员变量的调用
//	return 0;
//}



// 
// 类的默认成员函数
// 1、构造函数--在创建对象时，自动调用完成初始化
//	特点：
//			1、函数名与类名相同
//			2、无返回值
//			3、对象实例化时编译器自动调用对应的构造函数
//			4、构造函数可以重载
//			5、如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数
//			   当使用默认构造函数时，会将创建的对象中的属性设置一个随机值
//			   但是会将包含在其中的对象的值根据其类的构造函数初始化
//			   同时，一旦用户显示定义了构造函数，那么编译器将不再自动生成无参的构造函数。如果需要使用，则需要自己重新定义
// 2、析构函数--在对象生命周期结束后，自动调用，完成对象里面的资源（例如malloc动态开辟的空间）清理工作（不是对象的销毁）
// 特点：
//			1、析构函数名是在类名前加上~字符
//			2、无参数无返回值（不能构成重载函数）
//			3、一个类有且只有一个析构函数。如果未显示定义，则编译器会自动生成默认的析构函数
//				默认生成的析构函数会自动调用自定义类型的自定义函数
//			4、对象生命周期结束时，C++编译器会自动调用析构函数
//			5、不同对象的析构函数的先后调用是根据对象进入栈帧中的顺序
// 3、拷贝构造函数
//
class Date
{
public:
	// 构造函数（自定义值）
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 构造函数（默认值）
	// 如果在创建对象时不需要确认其参数，就可以利用重载函数的特点，为创建出来的对象设置一个默认值
	Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}*/
	// 全缺省的方式定义构造函数
	// 注意：
	//		无参的构造函数和缺省构造函数不能同时出现，不然会在调用时出现歧义
	//		这两个构造函数和编译器自动生成的构造函数被称为是默认构造函数
	//		默认构造函数只能有一个
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 析构函数
	~Date()
	{
		cout << "Date()" << endl;
	}

	// 拷贝构造函数
	
	// 这样调用拷贝构造，将d1传参之后，会在内部重新创建一个新的对象，而这个新对象需要初始化，由于这个新对象是拷贝构造来的，就需要重新再调用拷贝构造
	// 对于这个对象又要重新再调用拷贝构造，这样就会形成递归拷贝，导致编译不通过（类似于 套娃）
	/*Date(Date d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// 当不传参时，就会默认使用无参数的构造函数
	Date d1;
	d1.Print();
	d1.Init(2025, 1, 15);
	d1.Print();
	
	// 传参数时，就会使用有参数的构造函数
	// 具体使用根据重载函数的规则来确定
	Date d2(2025,1,15);
	d2.Print();

	Date d3(d2);



	return 0;
}