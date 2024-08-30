#include<iostream>

//using namespace std;	// C++库中的所有东西都是放到std命名空间中的
// 日常状态下，如果变量名少，不在乎变量名冲突，那么就可以将std直接展开
// 但是，这样展开会有一个缺点：如果程序员定义的变量名和std内部的名字相同就会出现冲突

using std::cout;
using std::cin;
using std::endl;
// 这种方式表示将std内部的一部分函数或者内容展开，此时可以直接调用展开部分；未展开部分调用则仍需要std的引用
// 一般是将常用的对象或者类型展开
// 工程项目中常用

// 例如，要想打印hello world，就需要利用到cout输出流函数
// 但是这个函数是被放到命名空间中的。
// 所以，要么提前将命名空间std（标准输入输出）声明好；要么就在使用到cout函数时将std带上
// 比如： std::cout<<"hello world";
//

//int main()
//{
//	//cout << "hello world!!\n"<<endl;	// 引用std命名空间之后的cout函数调用
//	// 这里的endl表示的也是换行符号的作用，和“\n”的效果相同
//	// 同时，endl调用和cout调用一样，也需要std的提前声明或者std的展开
//	//std::cout << "hello world";	// 未引用std命名空间后的调用方法
//	/*std::cout << "hello world"<<std::endl;*/
//
//	// 通过以下代码，可以发现C++的cout函数可以做到自动识别数据类型，不需要指定类型
//	// 这种能力是通过函数重载实现的
//	int i = 1;
//	double d = 1.11;
//	cin >> i >> d;
//	// 将控制台输入的数据分别流向变量i和变量d
//	std::cout << "i = "<< i << " " << "d = " << d << std::endl;
//
//	return 0;
//}


// 缺省参数
// 
//void Func(int a)
//{
//	cout << a << endl;
//}

// 这里面的形参a = 0就是缺省参数
// 如果在调用的时候没有对Func函数传入参数，那么就将缺省参数作为实参传入函数进行运行
// 可以理解为缺省参数就是备胎的意思
void Func(int a = 0)
{
	cout << a << endl;
}

// 缺省参数也有两种：
// 1、全缺省
// 2、半缺省
// 
// 注意：
// 不管是什么样子的缺省参数
// 1、调用时传参默认从左往右依次传入。即不能跳着传参
// 2、缺省的参数必须从右往左依次缺省。不能三个形参只有中间缺省
//

static void Func1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	//Func(10);
	//Func();

	Func1();
	Func1(1);
	Func1(1, 2);
	Func1(1, 2, 3);
	return 0;
}
