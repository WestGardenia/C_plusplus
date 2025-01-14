#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// 类的内部可以定义：
// 1、成员变量
// 2、成员方法
class Person {
	// 成员方法
public:
	// 表示公有方法
	void showinfo()
	{
		cout << _name << "-" << _sex << "-" << _age << endl;
	}
	// 成员变量（也叫类的属性）
//private:
	// 表示私有属性
	char _sex;
	const char* _name;
	int _age;
};
// 类中定义的内容可以分为公有和私有
// 公有的属性或者方法由public成员界定符确定
// 私有的属性或者方法由private成员界定符确定
// 保护的属性或者方法由project成员界定符确定
// class默认的定义属性是私有的，而struct默认的是公有的
//

int main()
{
	Person p1;
	// 私有属性不可以直接访问
	p1._name = "Peter";
	p1._age = 20;
	p1._sex = '1';
	p1.showinfo();

	return 0;
}