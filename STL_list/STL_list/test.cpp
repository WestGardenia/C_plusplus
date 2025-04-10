#include<iostream>
#include"list.h"
#include<list>
using namespace std;

void print_list(const list<int>& lt)
{
	list<int>::const_iterator  it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}


void test_list1()
{
	list<int> ls1;
	ls1.push_back(1);
	ls1.push_back(2);
	ls1.push_back(3);
	ls1.push_back(4);
	ls1.push_back(5);

	list<int>::iterator it = ls1.begin();
	while (it != ls1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	list<int> ls2;
	ls2.push_back(10);
	ls2.push_back(20);
	ls2.push_back(30);
	ls2.push_back(40);
	ls2.push_back(50);

	ls1 = ls2;
	for (auto e : ls1)
	{
		cout << e << " ";
	}
	cout << endl;
	print_list(ls1);

	list<int>::reverse_iterator rit = ls2.rbegin();
	while (rit != ls2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

// 从支持的操作接口的角度分迭代器的类型：单向（forword_list）、双向（list）、随机（vector）
// 从使用的场景的角度分迭代器的类型：（正向迭代器、反向迭代器）| const迭代器

void test_list2()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);

	ls.push_front(-1);
	ls.push_front(-2);
	ls.push_front(-3);
	ls.push_front(-4);

	print_list(ls);

	ls.pop_back();
	ls.pop_front();
	print_list(ls);
}

void test_list3()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.push_back(6);

	print_list(ls);
	list<int>::iterator pos = find(ls.begin(),ls.end(), 4);
	if (pos != ls.end())
	{
		// 在list中，这样先插入再删除的操作是可以被允许的
		// 但是再vector中，这样的操作会导致迭代器失效
		// 因为vector中的插入操作会将pos的位置发生改变，甚至有可能发生增容。pos就会失去原来的意义
		ls.insert(pos, 30);
		ls.erase(pos);
	}
	print_list(ls);

	ls.sort();
	print_list(ls);
}

void test_list4()
{
	list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.push_back(6);

	list<int>::iterator it = ls.begin();

	while (it != ls.end())
	{
		if (*it % 2 == 0)
		{
			// 像这样直接删除，在list中也会造成迭代器失效
			//ls.erase(it);
			// 应该在删除的同时将it的位置更新
			it = ls.erase(it);
		}
		else
		{
			it++;
		}
	}
	print_list(ls);
}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();

	//Dawn::test_list1();
	//Dawn::test_list2();
	//Dawn::test_list3();
	//Dawn::test_list4();
	Dawn::test_list5();
	return 0;
}