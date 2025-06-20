#include <iostream>
using namespace std;

// 1、非类型模板参数
//template<class T,int N>
//class A
//{
//public:
//	A()
//	{
//
//	}
//private:
//	// 这里的N就是非类型模板参数
//	T _a[N];
//};
//
//// 一般非类型模板参数都是int short long longlong char
//// double类型和自定义类型不能作为非类型模板参数
//
//int main()
//{
//	A<int, 100> a;	// 将N设置为100
//	return 0;
//}

// 2、模板的特化
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}

// 特化	(针对某些类型参数的特殊处理)
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left, right) == 0;
}

int main()
{
	const char* p1 = "hello";
	const char* p2 = "world";
	cout << IsEqual(p1, p2) << endl;
	return 0;
}

// 3、模板不能进行分离编译
//	所谓分离编译就是将函数和类的声明放到头文件中，将函数的定义和调用放到cpp函数源文件中，剩余的函数调用逻辑放在另一个源文件中
//	而模板在进行分离编译，即将模板函数和模板类的声明放到头文件中，就会在链接的过程出现问题
//	
// 我们知道，高级语言变成可执行文件需要4个步骤：
//	1、预处理	将头文件展开，对宏进行替换，去掉注释，进行条件编译
//	2、编译		检查语法，将高级语言转成汇编语言
//	3、汇编		将汇编代码转成二进制代码，生成目标文件（.o为后缀的文件）
//	4、链接		将目标文件合并，并生成可执行文件
// 
// 在上述的四个步骤中，编译会将源代码生成为汇编代码，即汇编指令。
// 而每一条汇编指令以及其变量都是有自己的地址的
// 这些地址会在函数定义的时候生成在系统中
// 在最终的链接过程中，CPU会根据函数或者类的地址去寻找对应的指令最终执行
// 
// 以上是正常的编译器处理代码的过程
// --------------------------------------------------------------------
// 而模板作为一个编译器自己推断其类型的对象，他的地址并不会在定义的时候生成——作为模板它本身并不知道自己是作为什么类型的
// 只有当后续的程序调用他的时候，编译器才知道他应该是什么类型从而对其进行推理生成
// 此时，分离编译的main.cpp中调用模板函数，那么在链接过程中CPU就无法得知对应的模板函数的地址，自然就链接失败了
// 
// 也就是说，在分离编译这种编程手段下
//	链接想要获取模板函数的地址，这就必须要确保模板函数对应的地址已经存在
//	但是模板函数的地址应该在模板函数被调用，也就是实例化后才能生成对应地址
// 这样就形成了编译器的左右脑互搏，最终会在链接过程报错
//