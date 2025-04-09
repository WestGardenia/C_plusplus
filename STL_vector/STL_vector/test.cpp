//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void test_vector1()
//{
//	vector<int>  v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	vector<int> v2(v1);
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//	for (size_t i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>  v3;
//	v3.push_back(10);
//	v3.push_back(20);
//	v3.push_back(30);
//	v3.push_back(40);
//	v1 = v3;
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//}
//
//void test_vector2()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	// �����޸�����
//	// 1��operator[] + size
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		v[i] *= 3;
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	// 2��������
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	// 3����Χfor
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void print_vector(const vector<int>& v)
//{
//	// �����const������������д
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//// ���������ݽṹ��֧�ַ�Χfor����operator[]
//// ֻ֧�ֵ�����
//void test_vector3()
//{
//	// �������͵�����
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	// ��ͨ��������� �ɶ���д
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	// const���͵ĵ�����
//	print_vector(v);
//
//	// ���������
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//}
//
//void test_vector4()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//	v.push_back(7);
//	v.push_back(8);
//
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	// windows�����ݵĹ�ģ��2���������Ч�ʣ������ܻ��˷ѿռ�
//	// linux�����ݵĹ�ģ��1.5����Ч�ʸ��ͣ����ռ������ʸ���
//}
//
//void test_vector5()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//
//	v[4] = 6;
//	v.at(3) = 5;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//}
//
//void test_vector6()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(20);
//	v.push_back(334);
//	v.push_back(434);
//	v.push_back(52);
//	v.push_back(25);
//	v.push_back(15);
//	v.push_back(5);
//	v.push_back(97);
//
//	// ͷ��
//	v.insert(v.begin(), 0);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// ɾ��vector�е�5
//	// ģ�庯��find����first��last����������ҵ�valֵ��λ�ò����䷵��
//	// ���û���ҵ����ͽ�last����
//	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
//	if (pos != v.end())
//	{
//		v.erase(pos);
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end());
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test_vector7()
//{
//	// ������ʧЧ����1������������
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//
//	vector<int>::iterator it = v.begin();
//
//	// �����ݹ����У�STL����һ��������ݵķ�ʽ���ռ俪�ٳ���
//	// ��������ָ���ԭ�ռ�ͻᱻ�ͷŵ�
//	// ��ʱ������ָ���λ�þ���һ�鲻Ӧ�ñ�ʹ�õĿռ�
//	//v.push_back(7);
//	//v.push_back(8);
//	//v.push_back(9);
//	//v.push_back(10);
//
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//void test_vector8()
//{
//	// ������ʧЧ����2
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//
//	// Ҫ��ɾ�������е�����ż��
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			//v.erase(it);	
//
//			//����ɾ��it֮��itָ�����Ȼ��ԭ����λ��
//			// �������λ�õ���������һ��λ�õ����ݲ���������
//			// ��������ĵ�����Ҳ��ʧЧ
//			// ����ʧЧ�ᱻVSֱ�Ӽ����� ---  ����gcc����������м�飬����gcc��ֻ���ܻ���ִ���Ľ��
//			it = v.erase(it);
//			// ��erase�ķ���ֵ����������ʱ���Ϳ��Ա�����������
//		}
//		else
//		{
//			it++;
//		}
//		
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	//test_vector1();
//	//test_vector2();
//	//test_vector3();
//	//test_vector4();
//	//test_vector5();
//	//test_vector6();
//	//test_vector7();
//	test_vector8();
//
//	return 0;
//}

#include"vector.h"

int main()
{
	//Dawn::test_vector1();
	//Dawn::test_vector2();
	//Dawn::test_vector3();
	//Dawn::test_vector4();
	Dawn::test_vector5();
	return 0;
}