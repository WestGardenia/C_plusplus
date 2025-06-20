#include<iostream>
#include"priority_queue.h"
#include<stack>
#include<queue>
#include<functional>

#include<algorithm>
using namespace std;

void test_stack1()
{
	stack<int> st;
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
	queue<int> q;
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

// 双端队列dequeue可以像数组一样随机访问，有数组一样的优点
// 但是它的缺点是随机访问和排序时效率很低，不适合直接用来代替vector和list
// 但是可以用它来作为栈或者队列的适配器，栈和队列并不会涉及到双端队列的缺点

// 优先级队列
// 容器适配器都不支持迭代器遍历，因为他们通常都包含一些特殊性质（比如队列的先进先出，栈的后进先出）
// 如果支持迭代器随机遍历，那他们无法保持他们各自性质
void test_priority_queue()
{
	// 底层是一个大堆
	//priority_queue<int> pq;	// 默认大的优先级高
	priority_queue<int, vector<int>,greater<int>> pq;	// 如果想变成小的优先级高	--> 仿函数
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);
	pq.push(7);
	// 得到的遍历序列是一个从大到小的顺序
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//// 除了默认访问限定符不一样，struct和class在C++中是一样的
//// 一般情况下，成员部分私有，部分公有，就用class
//// 所有成员都开放公有，就用struct
//struct less
//{
//	bool operator()(int x1, int x2)
//	{
//		return x1 < x2;
//	}
//};
//	|
//  |
// \ /


int main()
{
	//test_stack1();
	//test_queue1();
	//Dawn::test_stack1();
	//Dawn::test_queue1();
	// test_priority_queue();
	Dawn::test_priority_queue();
	// 
	// 
	// 这里的lessFunc不是一个函数，而是一个对象，调用的实际上是lessFunc中重载的operator()这样一个符号函数
	// 这就是仿函数 -- 函数对象，它的对象可以像函数一样去使用
	Dawn::less<int> lessFunc;
	cout << lessFunc(1, 2) << endl;

	return 0;
}