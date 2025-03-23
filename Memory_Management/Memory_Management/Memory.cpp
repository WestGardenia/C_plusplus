#include<iostream>

using namespace std;

//int main()
//{
//	// C 函数动态管理空间
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//
//	free(p1);
//	free(p3);
//
//
//	// C++ 操作符(也可以使用C中的函数）
//	int* p2 = new int();	// 括号里的值是开辟出来的空间初始化的值
//	int* p4 = new int[10];	// 方括号代表开辟10个int空间
//
//	delete p2;
//	delete[] p4;
//
//	return 0;
//}
// 对于动态开辟出来的空间来说，malloc函数和new操作符的作用是相同的
// 但是new和free对于自定义类型会调用构造函数和析构函数，而malloc函数不可以
// 1、针对内置类型用new和malloc都是一样的
// 2、针对自定义类型new还要调用构造函数完成初始化，delete还要调用析构函数完成清理
// 结论：C++中建议使用new/delete，
//

// C写法
//typedef struct ListNode_C {
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//}ListNode_C;
//
//// C++写法
//struct ListNode_CPP {
//	int _val;
//	struct ListNode_CPP* _next;
//	ListNode_CPP* _prev;	// 可以不加struct，在C++中，struct被认为时class类，区别在于默认访问限定符
//
//	// 构造函数（自定义值传参） -- 对应C中的BuyListNode_C
//	ListNode_CPP(int val,ListNode_CPP* next,ListNode_CPP* prev)
//	{
//		_val = val;
//		_next = next;
//		_prev = prev;
//	}
//
//	// 析构函数
//	~ListNode_CPP()
//	{
//		cout << "~ListNode_CPP() " << endl;
//	}
//};
//
//int main()
//{
//	ListNode_CPP* node1 = new ListNode_CPP(1,nullptr,nullptr);	// 在新创建时自动调用构造函数
//
//	delete node1;	// 在销毁时自动调用析构函数
//	return 0;
//}


// operator new和operator delete
//class A
//{
//public:
//	A(int a =0)
//	{
//		_a = a;
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A;
//	A* p3 = (A*)operator new(sizeof(A));
//	
//	// operatoe new 和malloc使用方式都是一样的，但是存在区别：
//	// 主要在于申请失败的区别：
//	// 申请空间是有可能失败的：例如一次申请的空间超过堆中的剩余空间，或者不断申请超过了堆的总空间
//	// malloc申请失败会返回0		（面向过程的错误处理方法）
//	// operator new申请失败会抛异常（面向对象处理错误的方法）
//	// 
//	// 同时，若是operator new申请的空间使用结束，就要使用operator delete(p3)来销毁
//	// 
//	// 另外。operator new实际上是用malloc实现的，只是在实现函数后加上了异常处理
//	// 所以
//	// operator new == malloc+失败抛异常
//	//			new	== operator new+构造函数
//	//
//
//	return 0;
//}


//int main()
//{
//	A* p = new A;
//	delete p;
//
//	// 想模拟new和delete函数的功能
//	// 即想要显式调用类的构造函数和析构函数
//	// 例如在开辟空间时，不在堆上开辟，而是在内存池上开辟
//	A* p2 = (A*)operator new(sizeof(A));
//	// 对已经存在的一块空间调用构造函数初始化(私有变量不能随意访问)
//	// 定位new/replacement new去显示调用构造函数
//	new(p2)A();
//	new(p2)A(10);	// new（开辟的空间的指针）类型（参数）
//
//	// 内存泄露：p指向的空间不需要了，但由于各种原因没有对其进行收回操作，所失去控制的这块空间就称之为内存泄漏
//	//	普通情况下，内存会随着进程结束而被回收，所以即使产生内存泄漏，也并没有太大危害
//	// 内存泄漏危害：长期运行中的程序，或者设备的内存本身很，或者僵尸进程。就会产生大量内存泄露
//	//
//
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}



// 模板
// 泛型编程：为了避免大量重复代码，通过代码复用实现
//template<class T>
//template<typename T>	// 模板类型参数
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//	printf("%d,%d\n", a, b);
//	cout << "a = " << a << " and b = " << b << endl;
//
//	double c = 1.01, d = 2.02;
//	Swap(c, d);
//	cout << "c = " << c << " and d = " << d << endl;
//
//	// 上面两次调用的Swap不是同一个函数
//	// 而是编译器在预处理阶段，对调用Swap这一命令，编译器自动对模板进行推演并生成一个新的函数
//	//
//
//	return 0;
//}


// C语言实现数据结构
// 问题 --> C++解决办法：
// 1、可能会存在忘记初始化和销毁		-->构造函数和析构函数
// 2、没有封装，谁都可以修改结构体数据  -->类+访问限定符
// 3、如果想同时定义两个相同的数据结构，但是数据类型不同，就需要两份代码 -- 既无法支持泛型编程   --> 模板解决问题
//

template<class T>

class Stack_CPP
{
public:
	Stack_CPP()
	{
		// 构造函数
	}
	~Stack_CPP()
	{
		// 析构函数
	}

	void Push(T val)
	{
		// 插入数据
	}
private:
	T* _a;
	int _size;
	int _capcity;
}; 

int main()
{
	Stack_CPP<int> st;
	// 创建类的实例化对象时会自动调用构造函数
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	// 在调用类的内部的函数时，同时也可以少加入一个参数，因为类内部的函数会自带this指针指向类的本身

	return 0;
	// 进程退出后 ，变量和对象的生命周期结束，系统会自动回收创建对象所使用的资源
}