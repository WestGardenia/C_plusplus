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