#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;
namespace Dawn
{
	// 栈和队列由于其各自的物理特性，不允许用户随便遍历
	// 因此栈和队列没有迭代器，只有适配器
	template<class T, class Container>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};

	template<class T, class Container>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& back()
		{
			return _con.back();
		}
		T& front()
		{
			return _con.front();
		}
	private:
		Container _con;
	};

	void test_stack1()
	{
		stack<int, vector<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

	void test_queue1()
	{
		// 队列的适配器不能使用vector，因为vector的顺序结构导致系统不提供效率低下的头插，所以队列也相应的不能使用vector
		queue<int, list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}
