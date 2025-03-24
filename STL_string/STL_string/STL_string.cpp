#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	// 无参构造
//	string s1;
//	// 带参构造
//	string s2("hello");
//	// 拷贝构造
//	string s3(s2);
//	// n个重复字符
//	string s4(10, 'a');
//
//	string s5 = "hello";	// 等价于s2的构造方式，将hello作为字符串进行拷贝构造，然后给s5进行拷贝构造
//	
//	string s6 = s2;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//
//
//	string s7("12345");
//	s7.push_back('6');	// 在原字符串基础上尾插一个字符
//	s7.append("78");		// 在原字符串基础上尾插一个字符串
//	//
//	// += 符号的效果等价于append函数
//	s7 += '1';			
//	s7 += "222";
//
//	cout << s7 << endl;
//
//	// 将字符数字转换成整型
//	string s8("123456");
//	int val = 0;
//	for (size_t i = 0; i < s8.size(); i++)
//	{
//		val *= 10;
//		val += (s8[i] - '0');	// 通过operate []进行遍历
//	}
//	cout << val << endl;
//
//
//	return 0;
//}


// 对于任何一个类，首先学习其4个默认成员函数
// 构造函数，拷贝构造，析构函数
void test_string1()
{
	string s1;
	string s2("hello");
	string s3("hello", 2);
	string s4 = s2;
	string s5("hello", 1, 2);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

}
int main()
{
	test_string1();
	return 0;
}