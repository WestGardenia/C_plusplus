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
//	// 遍历修改数据
//	// 1、operator[] + size
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		v[i] *= 3;
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	// 2、迭代器
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	// 3、范围for
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void print_vector(const vector<int>& v)
//{
//	// 这里的const迭代器不可以写
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//// 非线性数据结构不支持范围for或者operator[]
//// 只支持迭代器
//void test_vector3()
//{
//	// 三种类型迭代器
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	// 普通正向迭代器 可读可写
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	// const类型的迭代器
//	print_vector(v);
//
//	// 反向迭代器
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
//	// windows下增容的规模是2倍：提高了效率，但可能会浪费空间
//	// linux下增容的规模是1.5倍：效率更低，但空间利用率更高
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
//	// 头插
//	v.insert(v.begin(), 0);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// 删除vector中的5
//	// 模板函数find：从first到last这个区间中找到val值的位置并将其返回
//	// 如果没有找到，就将last返回
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
//	// 迭代器失效问题1——增容问题
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
//	// 在增容过程中，STL会以一种异地扩容的方式将空间开辟出来
//	// 而迭代器指向的原空间就会被释放掉
//	// 此时迭代器指向的位置就是一块不应该被使用的空间
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
//	// 迭代器失效问题2
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//
//	// 要求删除容器中的所有偶数
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			//v.erase(it);	
//
//			//这里删除it之后，it指向的仍然是原来的位置
//			// 但是这个位置的数据是下一个位置的数据补充上来的
//			// 所以这里的迭代器也会失效
//			// 这种失效会被VS直接检查出来 ---  但是gcc不会对他进行检查，所以gcc下只可能会出现错误的结果
//			it = v.erase(it);
//			// 将erase的返回值传给迭代器时，就可以避免这种问题
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