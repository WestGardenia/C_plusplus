#include<iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//		,_num(p._num)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			this->_name = p._name;
//			this->_num = p._num;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//public:
//	string _name = "����";
//	int _num = 999;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name),
//		_num(num)
//	{
//		cout << "Student(const char* name, int num)" << endl;
//	}
//	Student(const Student& s)
//		:_num(s._num)
//		,Person(s)	// �������ֱ�Ӱ����ഫ������Ŀ������졣�������������Ƭ����
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	void Print()
//	{
//		cout << "������" << _name << endl;
//		cout << "ѧ�ţ�" << _num << endl;
//		cout << "���֤�ţ�" << Person::_num << endl;
//	}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// ����Ҫ����ø�����������������һ��Ҫȷ��������
//			// ���������������ͬ�����غ���������ض��壬���ض����ʹ�ø����operator=����
//			// �����ٵ���operatro=���ǵ��������Լ�����ģ������ͻ���ɵݹ����
//			Person::operator=(s);	// ��������󴫸����ຯ����������Զ��������Ƭ����ֻ�������еĳ�Ա
//			_num = s._num;
//			cout << "Student& operator=(const Student& s)" << endl;
//		}
//	}
//	~Student()
//	{
//		// ��������������͸�������������ṹ������
//		// ��Ϊ���ǵĺ������ƻᱻ�����������destroy
//		// ͬʱ����������������Ĺ����У�����ջ�����ԣ�
//		//		���๹��->���๹��->��������->��������
//		// ����������������Ҫ������ʾ���ø������������
//		// ���������������Զ����ø���������������������ܱ�֤���������࣬�����������˳��
//		//Person::~Person();
//		cout << "~Student()" << endl;
//	}
//public:
//	int _num = 111;
//};

// 1���̳��ำֵ����
// ������Ը����ำֵ������ֵ/ָ��/����
// ���Ǹ��಻�ܸ����ำֵ�����䲻��ֱ�Ӵ�ֵ
//
// 2�������������ͬʱ��ͬ����Աʱ�������Ա�����ظ����Ա���ض��壩
//		�ض�������ص�����
//			���أ�����Ҫ����ͬһ�������£���������ͬ��������ͬ
//			�ض��壺�ڲ�ͬ�������£�����ͬ�ĺ��������߳�Ա��
//		������������������Ѱ�ң��ٵ�������Ѱ��
// ���ȷʵҪ���ʸ����ͬ����Ա���Ǿ�Ҫָ��������
//
// 3��������һ�����ܱ��̳е���
//	���������캯��˽�С�������Ҫ���й����һ��Ҫ���ø���Ĺ��캯�������Ǹ��๹�캯��˽�о��޷�����
// 
// 4����Ԫ��Ա�޷��̳�
// 5����̬��Ա���Լ̳У����Ǽ̳���������ͬһ��ռ䣬��������ľ�̬��Ա���в���Ҳ��ֱ�Ӹı丸��ľ�̬��Ա
// 
// �̳еı����Ǹ���
// ��̳оͻ�������μ̳�
// ���μ̳����������ݵ�����Ͷ����ԡ���ĳһ����ͬʱ��������ͬ�ĸ���
// 
// �����⣺C++��ȱ�ݣ���̳лᵼ�����μ̳�
//			����ķ�������̳У�����virtual�ֶ� 
//	
// 
//int main()
//{
//	//Person p;
//	//Student s("Peter",1);
//	//s.Print();
//	//Student s1(s);
//	//Student s2 = s1;
//	//s2.Print();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B :virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :virtual public B, virtual public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	cout << sizeof(d) << endl;
//	// ʵ���У������򲻵��ѣ���Ҫ�ö�̳�
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 6;
//	return 0;
//}

// �̳к����
// �̳�
// ��һ�ְ��临�ã�����������������͸���ģ�������ܻ��ƻ�����ķ�װ
class A{};
class B :public A
{ };

// ���
// ��һ�ֺ��临�ã�C����D�ǲ�͸���ģ�C���Ա������ķ�װ
class C{};
class D
{
	C c;
};

// ��ϵ���϶ȸ��ͣ����̳е�����һ�ָ����
// ����д��Ҫ���������
// ���һ���ǰ���ӵ�еĹ�ϵ	�����磺������̥��
// �̳�һ���� �� �Ĺ�ϵ		�����磺��ʦ���ˣ�