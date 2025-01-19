#include<iostream>
using std::cout;
using std::cin;
using std::endl;


// 1、求1+2+3+4+……+n，要求不能使用乘除法、for、while、if、else、switch、case、等关键字及递归和条件判断语句
// 分析：由于本题不允许使用各种循环以及递归的方式处理问题，所以考虑使用计算机底层逻辑以及c++语法特点
//		考虑到C++中类的构造函数是可以在将类的对象实例化时自动调用的，那么就可以创建n类的数组，利用构造函数将执行n次加法实现出来
//		再利用静态区的变量保留住每次加法后改变的变量，这样就可以实现前n项和
// 注意：由于本题使用了静态区的资源，所以在进行多次调用时，下一次的测试会从上一次的保留的结果继续运行
//		 因此在每次调用之前需要将静态变量进行初始化
class Sum {
public:
	Sum()
	{
		_sum += _i;
		_i++;
	}
	static void Init()
	{
		_i = 1;
		_sum = 0;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};

int Sum::_i = 1;
int Sum::_sum = 0;
class Solution
{
public:
	int Sum_Solution(int n)
	{
		// Sum s[n];	// 变长数组（C语言中C99版本支持）
		Sum::Init();
		Sum* p = new Sum[n];
		return Sum::GetSum();
	}
	
};

int Sum_1(int n)
{
	return (1 + n) * n / 2;
}

int main()
{
	Solution S1;
	cout << S1.Sum_Solution(115) << endl;
	cout << S1.Sum_Solution(115) << endl;
	cout << Sum_1(115) << endl;
	return 0;
}