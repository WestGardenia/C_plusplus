#pragma once
#include<iostream>
#include<cassert>
using namespace std;
namespace Dawn {
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{ }
	};
	// __list_iterator<T,T&,T*> -> iterator
	// __list_iterator<T,const T&,const T*> -> const_iterator
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T,Ref,Ptr> Self;
		node* _node;
		__list_iterator(node* node)
			:_node(node)
		{ }

		// *it
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it
		Self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// --it
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		// it++
		Self& operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		// it++
		Self& operator--(int)
		{
			Self tmp(*this);
			//_node = _node->_prev;
			--(*this);
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;

	public:
		typedef __list_iterator<T,T&,T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			_tail = _head;
		}
		list(const list<T>& ls)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			_tail = _head;

			const_iterator it = ls.begin();
			while (it != ls.end())
			{
				push_back(*it);
				it++;
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()	const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()	const
		{
			return const_iterator(_head);
		}
		void push_back(const T& x)
		{
			node* newnode = new node;
			newnode->_data = x;
			_tail->_next = newnode;
			_head->_prev = newnode;

			newnode->_next = _head;
			newnode->_prev = _tail;

			_tail = newnode;
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = pos._node->_prev;
			node* newnode = new node(x);
			// prev -> newnode -> cur
			newnode->_next = cur;
			newnode->_prev = prev;

			prev->_next = newnode;
			cur->_prev = newnode;
		}
		void erase(iterator pos)
		{
			assert(pos != end());
			node* tmp = pos._node;
			tmp->_prev->_next = tmp->_next;
			tmp->_next->_prev = tmp->_prev;
			delete tmp;
		}
		// 两种赋值函数的写法
		// 1、传统写法
		//list<T>& operator=(const list<T>& ls)
		//{
		//	if (this != &ls)
		//	{
		//		// 首先要清除自身内部原有的数据和节点
		//		clear();
		//		for (auto e : ls)
		//		{
		//			push_back(e);
		//		}
		//	}
		//}
		// 2、现代写法
		list<T>& operator=(list<T> ls)
		{
			swap(_head, ls._head);
			return *this;
		}

	private:
		node* _head;
		node* _tail;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct Date
	{
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

	void test_list2()
	{
		list<struct Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());

		list<struct Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it)._year << '-' << (*it)._month << '-' << (*it)._day << endl;
			cout << it->_year << '-' << it->_month << '-' << it->_day << endl;
			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		lt.erase(++it);

		it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void print_list(const list<int>& ls)
	{
		list<int>::const_iterator it = ls.begin();
		while (it != ls.end())
		{
			//*it = 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		print_list(lt);

		lt.pop_back();
		lt.pop_back();
		lt.pop_back();

		print_list(lt);
	}

	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		print_list(lt);

		list<int> lt2(lt);
		print_list(lt2);

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);
		lt3.push_back(40);
		lt3.push_back(50);
		print_list(lt3);

		lt3 = lt;
		print_list(lt3);
	}
}
