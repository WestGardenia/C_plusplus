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
	string s6("hello", 1, string::npos);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

}

// 1、遍历
void test_string2()
{
	string s1("hello");
	s1 += " world";

	// operator []
	// 读
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	// 写
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;
	}
	cout << endl;

	// 迭代器
	// 范围for的原理就是迭代器
	// for(auto ch : s1)
	// {
	//		cout << ch << " ";
	// }
	// 写
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	cout << endl;
	// 读
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}

int string2int(const string& str)	// string2int == StringToInt
{
	int val = 0;
	// const迭代器只能读不能写
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		it++;
	}
	return val;
}

// 再看其他迭代器
void test_string3()
{
	string s1("hello world");
	// 倒着遍历
	//string::reverse_iterator rit = s1.rbegin();		// 反向迭代器
	auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	string nums("12345");
	cout << string2int(nums) << endl;

}

void test_string4()
{
	string s1("hello world");
	string s2("hello");

	cout << s1.size() << endl;
	cout << s2.size() << endl;

	cout << s1.length() << endl;
	cout << s2.length() << endl;

	// 展示string的最大长度
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	// 检查string的最大容量
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	// 清空
	s1.clear();
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test_string5()
{
	//string s;
	//// reserve函数可以直接开辟对应空间，避免多次增容带来的内存消耗
	//// 直接开辟对应大于100的空间（需要考虑内存对齐的问题）
	//s.reserve(100);
	////s.resize(100);
	//size_t sz = s.capacity();
	//for (size_t i = 0; i < 100; i++)
	//{
	//	s.push_back('c');
	//	if (sz != s.capacity())
	//	{
	//		// 每次尾插字符后，如果字符量大于容量，就记录
	//		sz = s.capacity();
	//		cout << "capacity change:" << sz << endl;
	//	}
	//}

	//string s("hello world");
	//s.resize(5);
	//s.resize(20, 'x');
}

// 插入
void test_string6()
{
	string s;
	s.push_back('x');
	s.append("-man");

	s += " war";
	cout << s << endl;

	s.insert(2, "whilt");
	cout << s << endl;

	s.clear();
	s.insert(s.begin(),'0');
	cout << s << endl;


	s.insert(s.begin(), '1');
	cout << s << endl;

	s += "23456";
	cout << s << endl;

	s.erase(2, 3);
	cout << s << endl;
}

void test_string7()
{
	string s("hello world");
	// 获取字符数组的首地址，用C字符串的形式遍历
	// 如果string中含有'\0'，那么调用c_str接口在\0后就会不可见
	const char* str = s.c_str();
	while (*str != '\0')
	{
		cout << *str << " ";
		str++;
	}
	//调用string重载的operator <<
	cout << endl << s << endl;
	// 直接输出const char*
	cout << endl << s.c_str() << endl;

	s += '\0';
	s += "!!!!";

	cout << s << endl;
	cout << s.c_str() << endl;

	/*for (unsigned char ch = 0; ch < 128; ch++)
	{
		cout << ch << "  ";
	}*/

	char str1[] = "中国";
	cout << str1 << endl;
	str1[3] = -87;
	cout << str1 << endl;
	str1[3] = -85;
	cout << str1 << endl;
}

void test_string8()
{
	string s1("string.cpp");
	string s2("string.c");
	string s3("string.txt");
	
	// 确定文件格式
	// find：从前往后找
	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
	}
	// 为避免有多个.txt.tar类似的后缀
	// rfind：从后往前找
	size_t pos2 = s2.rfind('.');
	if (pos2 != string::npos)
	{
		cout << pos2 << endl;
		cout << s2.substr(pos2) << endl;
	}
	size_t pos3 = s3.find('.');
	if (pos3 != string::npos)
	{
		cout << s3.substr(pos3) << endl;
	}

	// https://account.chsi.com.cn/account/account!show.action
	string url("https://account.chsi.com.cn/account/account!show.action");
	// 分离出网址的 协议、域名、资源名称
	size_t i1 = url.find(':');	// 找到协议后的':'
	if (i1 != url.npos)
	{
		cout << "协议：" << url.substr(0, i1) << endl;
	}

	size_t i2 = url.find('/', i1 + 3);
	if (i2 != url.npos)
	{
		cout << "域名：" << url.substr(i1 + 3, i2 - (i1 + 3)) << endl;
	}
	cout << "资源：" << url.substr(i2 + 1, url.npos);
}

void test_string9()
{
	string s1("abcd");
	string s2("efgh");
	cout << (s1 < "aaaa") << endl;
}

//int main()
//{
//	// test_string1();
//	// test_string2();
//	// test_string3();
//	// test_string4();
//	// test_string5();
//	// test_string6();
//	// test_string7();
//	// test_string8();
//	test_string9();
//	return 0;
//}