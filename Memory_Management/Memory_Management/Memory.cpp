#include<iostream>

using namespace std;

//int main()
//{
//	// C ������̬����ռ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//
//	free(p1);
//	free(p3);
//
//
//	// C++ ������(Ҳ����ʹ��C�еĺ�����
//	int* p2 = new int();	// �������ֵ�ǿ��ٳ����Ŀռ��ʼ����ֵ
//	int* p4 = new int[10];	// �����Ŵ�����10��int�ռ�
//
//	delete p2;
//	delete[] p4;
//
//	return 0;
//}
// ���ڶ�̬���ٳ����Ŀռ���˵��malloc������new����������������ͬ��
// ����new��free�����Զ������ͻ���ù��캯����������������malloc����������
// 1���������������new��malloc����һ����
// 2������Զ�������new��Ҫ���ù��캯����ɳ�ʼ����delete��Ҫ�������������������
// ���ۣ�C++�н���ʹ��new/delete��
//

// Cд��
//typedef struct ListNode_C {
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//}ListNode_C;
//
//// C++д��
//struct ListNode_CPP {
//	int _val;
//	struct ListNode_CPP* _next;
//	ListNode_CPP* _prev;	// ���Բ���struct����C++�У�struct����Ϊʱclass�࣬��������Ĭ�Ϸ����޶���
//
//	// ���캯�����Զ���ֵ���Σ� -- ��ӦC�е�BuyListNode_C
//	ListNode_CPP(int val,ListNode_CPP* next,ListNode_CPP* prev)
//	{
//		_val = val;
//		_next = next;
//		_prev = prev;
//	}
//
//	// ��������
//	~ListNode_CPP()
//	{
//		cout << "~ListNode_CPP() " << endl;
//	}
//};
//
//int main()
//{
//	ListNode_CPP* node1 = new ListNode_CPP(1,nullptr,nullptr);	// ���´���ʱ�Զ����ù��캯��
//
//	delete node1;	// ������ʱ�Զ�������������
//	return 0;
//}


// operator new��operator delete
//class A
//{
//public:
//	A(int a =0)
//	{
//		_a = a;
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A;
//	A* p3 = (A*)operator new(sizeof(A));
//	
//	// operatoe new ��mallocʹ�÷�ʽ����һ���ģ����Ǵ�������
//	// ��Ҫ��������ʧ�ܵ�����
//	// ����ռ����п���ʧ�ܵģ�����һ������Ŀռ䳬�����е�ʣ��ռ䣬���߲������볬���˶ѵ��ܿռ�
//	// malloc����ʧ�ܻ᷵��0		��������̵Ĵ���������
//	// operator new����ʧ�ܻ����쳣��������������ķ�����
//	// 
//	// ͬʱ������operator new����Ŀռ�ʹ�ý�������Ҫʹ��operator delete(p3)������
//	// 
//	// ���⡣operator newʵ��������mallocʵ�ֵģ�ֻ����ʵ�ֺ�����������쳣����
//	// ����
//	// operator new == malloc+ʧ�����쳣
//	//			new	== operator new+���캯��
//	//
//
//	return 0;
//}


//int main()
//{
//	A* p = new A;
//	delete p;
//
//	// ��ģ��new��delete�����Ĺ���
//	// ����Ҫ��ʽ������Ĺ��캯������������
//	// �����ڿ��ٿռ�ʱ�����ڶ��Ͽ��٣��������ڴ���Ͽ���
//	A* p2 = (A*)operator new(sizeof(A));
//	// ���Ѿ����ڵ�һ��ռ���ù��캯����ʼ��(˽�б��������������)
//	// ��λnew/replacement newȥ��ʾ���ù��캯��
//	new(p2)A();
//	new(p2)A(10);	// new�����ٵĿռ��ָ�룩���ͣ�������
//
//	// �ڴ�й¶��pָ��Ŀռ䲻��Ҫ�ˣ������ڸ���ԭ��û�ж�������ջز�������ʧȥ���Ƶ����ռ�ͳ�֮Ϊ�ڴ�й©
//	//	��ͨ����£��ڴ�����Ž��̽����������գ����Լ�ʹ�����ڴ�й©��Ҳ��û��̫��Σ��
//	// �ڴ�й©Σ�������������еĳ��򣬻����豸���ڴ汾��ܣ����߽�ʬ���̡��ͻ���������ڴ�й¶
//	//
//
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}



// ģ��
// ���ͱ�̣�Ϊ�˱�������ظ����룬ͨ�����븴��ʵ��
//template<class T>
//template<typename T>	// ģ�����Ͳ���
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//	printf("%d,%d\n", a, b);
//	cout << "a = " << a << " and b = " << b << endl;
//
//	double c = 1.01, d = 2.02;
//	Swap(c, d);
//	cout << "c = " << c << " and d = " << d << endl;
//
//	// �������ε��õ�Swap����ͬһ������
//	// ���Ǳ�������Ԥ����׶Σ��Ե���Swap��һ����������Զ���ģ��������ݲ�����һ���µĺ���
//	//
//
//	return 0;
//}


// C����ʵ�����ݽṹ
// ���� --> C++����취��
// 1�����ܻ�������ǳ�ʼ��������		-->���캯������������
// 2��û�з�װ��˭�������޸Ľṹ������  -->��+�����޶���
// 3�������ͬʱ����������ͬ�����ݽṹ�������������Ͳ�ͬ������Ҫ���ݴ��� -- ���޷�֧�ַ��ͱ��   --> ģ��������
//

template<class T>

class Stack_CPP
{
public:
	Stack_CPP()
	{
		// ���캯��
	}
	~Stack_CPP()
	{
		// ��������
	}

	void Push(T val)
	{
		// ��������
	}
private:
	T* _a;
	int _size;
	int _capcity;
}; 

int main()
{
	Stack_CPP<int> st;
	// �������ʵ��������ʱ���Զ����ù��캯��
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	// �ڵ�������ڲ��ĺ���ʱ��ͬʱҲ�����ټ���һ����������Ϊ���ڲ��ĺ������Դ�thisָ��ָ����ı���

	return 0;
	// �����˳��� �������Ͷ�����������ڽ�����ϵͳ���Զ����մ���������ʹ�õ���Դ
}