#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//namespace Dawn
//{
//	// 实现一个简单的string --> 深浅拷贝问题
//	class string
//	{
//	public:
//		// 1、构造函数
//		// 重载版本
//		//string()
//		//{
//		//	_str = new char[1];
//		//	_str[0] = '\0';
//		//}
//		//string(const char* str)
//		//	:_str(new char[strlen(str) + 1])
//		//{
//		//	// +1是为了使创建出来的字符串符合C的习惯，即字符串末尾需要留一个位置给 '\0'
//		//	strcpy(_str, str);
//		//}
//
//		// 全缺省版本
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		} 
//		// 2、拷贝构造 --> 深拷贝
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		// 3、析构函数
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		size_t size()
//		{
//			return strlen(_str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				// s1 = s3 
//				// 1、开一段和s3相同的空间tmp
//				// 2、将s1原来的旧空间释放，并将s1指向新开的空间
//				// 3、最后将s1指针返回
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello");
//		string s2;
//		for (size_t i = 0; i < s1.size(); i++)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//	}
//
//	void test_string2()
//	{
//		string s1("hello");
//		string s2(s1);
//		// 如果没有自己定义拷贝构造函数，就会默认使用编译器自定义的拷贝构造，此时是浅拷贝
//		// 而浅拷贝会将s2的指针指向s1的空间
//		// 那么在进程退出后，s2的空间被析构的同时，s1的空间也被析构，并将s1置为nullptr
//		// 在此之后，s1要再次被析构，但此时s1已经是空，调用空指针就会形成野指针
//		// 故而，在这里要自定义拷贝构造，并实现深拷贝
//		cout << "s1: " << s1.c_str() << endl;
//		cout << "s2: " << s2.c_str() << endl;
//		string s3;
//
//		s3 = s1;
//		cout << "s3: " << s3.c_str() << endl;
//	}
//}


namespace Dawn
{
	class string
	{
	public:
		typedef char* iterator;	// 用char* 封装了一个迭代器的类型
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// 拷贝构造
		// 1、传统写法
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		// 2、现代写法
		// 本质上就是将拷贝的逻辑外包给构造函数去实现
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			// 先利用被拷贝的string中的字符串创建一个新的string对象
			string tmp(s._str);
			// 再将两者的_str交换
			// 但由于新创建的s2中的_str是随机值，所以要先将其置为空
			swap(tmp);
		}
		void swap(string& s)
		{
			// 要加上域作用限定符
			// 直接写swap会优先调用自己写的swap(string& s)
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
		}
		size_t size()	const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}

		// 将容量扩大到newcapacity
		void reserve(size_t newcapacity)
		{
			if(newcapacity > _capacity)
			{
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				// 扩容
				size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
				reserve(newcapacity);
			}
			_str[_size] = ch;
			_size++;
			// 如果插入字符后正好满了，那么就会把'\0'的位置覆盖掉，这时在调用<<运算符就会造成指针越界
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_capacity < _size + len)
			{
				//扩容
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size = _size + len;
		}

		string& operator += (char ch)
		{
			this->push_back(ch);
			return *this;
		}

		string& operator += (const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (this->_size + 1 == _capacity)
			{
				size_t newcapacity = (_capacity == 0 ? 2 : 2 * _capacity);
				reserve(newcapacity);
			}
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t str_end = strlen(str);
			// 扩容
			if (_size + str_end > _capacity)
			{
				size_t newcapacity = (_capacity == 0 ? str_end : _capacity + str_end);
				reserve(newcapacity);
			}
			// 挪动数据
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + str_end] = _str[end];
				end--;
			}
			// 将新数据填入为之空出来的空间
			for (int i = 0; i < str_end; i++)
			{
				_str[pos] = str[i];
				pos++;
			}
			// strncpy(_str+pos ,str, str_end);
			_size = _size + str_end;

			return *this;
		}
		void erase(size_t pos, size_t len = npos)
		{
			// 删除pos之后的len个字符
			assert(pos < _size);
			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					i++;
				}
				_size -= len;
			}
		}
		size_t find(char ch, size_t pos = 0)
		{
			size_t i = pos;
			while (i< _size)
			{
				if (_str[i] == ch)
				{
					return i;
				}
				i++;
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			// strstr子串匹配函数（KMP算法）
			char* p = strstr(_str, str);
			if (p == nullptr)
			{
				return npos;
			}
			return p - _str;
		}

		bool operator>(const string& str)
		{
			int ret = strcmp(_str, str._str);
			return  ret > 0;
		}
		bool operator==(const string& str)
		{
			int ret = strcmp(_str, str._str);
			return  ret == 0;
		}
		bool operator<(const string& str)
		{
			return !(*this > str);
		}
		bool operator<=(const string& str)
		{
			return *this < str || *this == str;
		}
		bool operator>=(const string& str)
		{
			return  *this > str || *this == str;
		}

	private:
		char* _str;
		static const size_t npos = -1;
		size_t _size;		// 已有的字符串中字符数量
		size_t _capacity;	// 当前字符串的最大可容纳有效字符数量，不包括'\0'
	};

	ostream& operator << (ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}

	istream& operator >> (istream& in, string& s)
	{
		while (1)
		{
			char ch;
			//in >> ch;
			// 这里不能直接用系统给的输入流
			// 系统给的输入流会将输入的字符打入缓冲区，而缓冲区会自动认为空格和换行是用户一次输入的停止标识，所以缓冲区不会接受得到换行符和空格
			ch = in.get();
			if (ch == '\n' || ch == ' ')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}

	void test_string1()
	{
		string s1;
		string s2("hello");

		cout << s2.c_str() << endl;
		cout << s2 << endl;

		// []运算符遍历
		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 1;
			cout << s2[i] << " ";
		}
		cout << endl;

		// 迭代器遍历
		string::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			*it2 -= 1;
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;
		// 范围for
		// 范围for是由迭代器支持的，即这段代码最终会被编译器替换成迭代器的代码
		for (auto ch : s2)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s("hello");
		s.push_back('h');
		s.push_back('e');
		s.push_back('l');
		s.push_back('l');
		s.push_back('o');

		cout << s <<endl;

		s.append("world");
		cout << s << endl;

		s += "!!!!";
		cout << s << endl;
	}

	void test_string3()
	{
		string s("hello");
		char str[] = " world";
		s = s.insert(s.size(), str);
		cout << s << endl;

		cout << s.size() << endl;
		cout << s.capacity() << endl << endl;

		string s2("hello");
		s2.resize(18, 'x');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;

		string s3("hello");
		s3.resize(8);
		cout << s3 << endl;
		cout << s3.size() << endl;
		cout << s3.capacity() << endl<<endl;
		
		s2.erase(2, 26);
		cout << s2 << endl;

		string s4("abcdefg");
		cout << s4.find("cdex") << endl;
		cout << s4.find("cde") << endl;
	}

	void test_string4()
	{
		string s;
		cin >> s;
		cout << s << endl;
	}
}