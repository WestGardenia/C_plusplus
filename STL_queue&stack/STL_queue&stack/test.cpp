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

// ˫�˶���dequeue����������һ��������ʣ�������һ�����ŵ�
// ��������ȱ����������ʺ�����ʱЧ�ʺܵͣ����ʺ�ֱ����������vector��list
// ���ǿ�����������Ϊջ���߶��е���������ջ�Ͷ��в������漰��˫�˶��е�ȱ��

// ���ȼ�����
// ��������������֧�ֵ�������������Ϊ����ͨ��������һЩ�������ʣ�������е��Ƚ��ȳ���ջ�ĺ���ȳ���
// ���֧�ֵ���������������������޷��������Ǹ�������
void test_priority_queue()
{
	// �ײ���һ�����
	//priority_queue<int> pq;	// Ĭ�ϴ�����ȼ���
	priority_queue<int, vector<int>,greater<int>> pq;	// �������С�����ȼ���	--> �º���
	pq.push(3);
	pq.push(1);
	pq.push(9);
	pq.push(4);
	pq.push(2);
	pq.push(7);
	// �õ��ı���������һ���Ӵ�С��˳��
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//// ����Ĭ�Ϸ����޶�����һ����struct��class��C++����һ����
//// һ������£���Ա����˽�У����ֹ��У�����class
//// ���г�Ա�����Ź��У�����struct
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
	// �����lessFunc����һ������������һ�����󣬵��õ�ʵ������lessFunc�����ص�operator()����һ�����ź���
	// ����Ƿº��� -- �����������Ķ����������һ��ȥʹ��
	Dawn::less<int> lessFunc;
	cout << lessFunc(1, 2) << endl;

	return 0;
}