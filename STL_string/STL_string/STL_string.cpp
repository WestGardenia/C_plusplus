#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	// �޲ι���
//	string s1;
//	// ���ι���
//	string s2("hello");
//	// ��������
//	string s3(s2);
//	// n���ظ��ַ�
//	string s4(10, 'a');
//
//	string s5 = "hello";	// �ȼ���s2�Ĺ��췽ʽ����hello��Ϊ�ַ������п������죬Ȼ���s5���п�������
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
//	s7.push_back('6');	// ��ԭ�ַ���������β��һ���ַ�
//	s7.append("78");		// ��ԭ�ַ���������β��һ���ַ���
//	//
//	// += ���ŵ�Ч���ȼ���append����
//	s7 += '1';			
//	s7 += "222";
//
//	cout << s7 << endl;
//
//	// ���ַ�����ת��������
//	string s8("123456");
//	int val = 0;
//	for (size_t i = 0; i < s8.size(); i++)
//	{
//		val *= 10;
//		val += (s8[i] - '0');	// ͨ��operate []���б���
//	}
//	cout << val << endl;
//
//
//	return 0;
//}


// �����κ�һ���࣬����ѧϰ��4��Ĭ�ϳ�Ա����
// ���캯�����������죬��������
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

// 1������
void test_string2()
{
	string s1("hello");
	s1 += " world";

	// operator []
	// ��
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	// д
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;
	}
	cout << endl;

	// ������
	// ��Χfor��ԭ����ǵ�����
	// for(auto ch : s1)
	// {
	//		cout << ch << " ";
	// }
	// д
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	cout << endl;
	// ��
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
	// const������ֻ�ܶ�����д
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		it++;
	}
	return val;
}

// �ٿ�����������
void test_string3()
{
	string s1("hello world");
	// ���ű���
	//string::reverse_iterator rit = s1.rbegin();		// ���������
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

	// չʾstring����󳤶�
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	// ���string���������
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	// ���
	s1.clear();
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test_string5()
{
	//string s;
	//// reserve��������ֱ�ӿ��ٶ�Ӧ�ռ䣬���������ݴ������ڴ�����
	//// ֱ�ӿ��ٶ�Ӧ����100�Ŀռ䣨��Ҫ�����ڴ��������⣩
	//s.reserve(100);
	////s.resize(100);
	//size_t sz = s.capacity();
	//for (size_t i = 0; i < 100; i++)
	//{
	//	s.push_back('c');
	//	if (sz != s.capacity())
	//	{
	//		// ÿ��β���ַ�������ַ��������������ͼ�¼
	//		sz = s.capacity();
	//		cout << "capacity change:" << sz << endl;
	//	}
	//}

	//string s("hello world");
	//s.resize(5);
	//s.resize(20, 'x');
}

// ����
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
	// ��ȡ�ַ�������׵�ַ����C�ַ�������ʽ����
	// ���string�к���'\0'����ô����c_str�ӿ���\0��ͻ᲻�ɼ�
	const char* str = s.c_str();
	while (*str != '\0')
	{
		cout << *str << " ";
		str++;
	}
	//����string���ص�operator <<
	cout << endl << s << endl;
	// ֱ�����const char*
	cout << endl << s.c_str() << endl;

	s += '\0';
	s += "!!!!";

	cout << s << endl;
	cout << s.c_str() << endl;

	/*for (unsigned char ch = 0; ch < 128; ch++)
	{
		cout << ch << "  ";
	}*/

	char str1[] = "�й�";
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
	
	// ȷ���ļ���ʽ
	// find����ǰ������
	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
	}
	// Ϊ�����ж��.txt.tar���Ƶĺ�׺
	// rfind���Ӻ���ǰ��
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
	// �������ַ�� Э�顢��������Դ����
	size_t i1 = url.find(':');	// �ҵ�Э����':'
	if (i1 != url.npos)
	{
		cout << "Э�飺" << url.substr(0, i1) << endl;
	}

	size_t i2 = url.find('/', i1 + 3);
	if (i2 != url.npos)
	{
		cout << "������" << url.substr(i1 + 3, i2 - (i1 + 3)) << endl;
	}
	cout << "��Դ��" << url.substr(i2 + 1, url.npos);
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