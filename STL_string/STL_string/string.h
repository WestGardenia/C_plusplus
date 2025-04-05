#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//namespace Dawn
//{
//	// ʵ��һ���򵥵�string --> ��ǳ��������
//	class string
//	{
//	public:
//		// 1�����캯��
//		// ���ذ汾
//		//string()
//		//{
//		//	_str = new char[1];
//		//	_str[0] = '\0';
//		//}
//		//string(const char* str)
//		//	:_str(new char[strlen(str) + 1])
//		//{
//		//	// +1��Ϊ��ʹ�����������ַ�������C��ϰ�ߣ����ַ���ĩβ��Ҫ��һ��λ�ø� '\0'
//		//	strcpy(_str, str);
//		//}
//
//		// ȫȱʡ�汾
//		string(const char* str = "")
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		} 
//		// 2���������� --> ���
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		// 3����������
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
//				// 1����һ�κ�s3��ͬ�Ŀռ�tmp
//				// 2����s1ԭ���ľɿռ��ͷţ�����s1ָ���¿��Ŀռ�
//				// 3�����s1ָ�뷵��
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
//		// ���û���Լ����忽�����캯�����ͻ�Ĭ��ʹ�ñ������Զ���Ŀ������죬��ʱ��ǳ����
//		// ��ǳ�����Ὣs2��ָ��ָ��s1�Ŀռ�
//		// ��ô�ڽ����˳���s2�Ŀռ䱻������ͬʱ��s1�Ŀռ�Ҳ������������s1��Ϊnullptr
//		// �ڴ�֮��s1Ҫ�ٴα�����������ʱs1�Ѿ��ǿգ����ÿ�ָ��ͻ��γ�Ұָ��
//		// �ʶ���������Ҫ�Զ��忽�����죬��ʵ�����
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
		typedef char* iterator;	// ��char* ��װ��һ��������������
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

		// ����������newcapacity
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

		void resize(size_t n, char ch)
		{

		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				// ����
				size_t newcapacity = (_capacity == 0 ? 2 : _capacity * 2);
				reserve(newcapacity);
			}
			_str[_size] = ch;
			_size++;
			// ��������ַ����������ˣ���ô�ͻ��'\0'��λ�ø��ǵ�����ʱ�ڵ���<<������ͻ����ָ��Խ��
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_capacity < _size + len)
			{
				//����
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
			while (end >= pos)
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
			int str_end = strlen(str);
			// ����
			if (_size + str_end > _capacity)
			{
				size_t newcapacity = (_capacity == 0 ? str_end : _capacity + str_end);
				reserve(newcapacity);
			}
			// Ų������
			int end = _size;
			while (end > pos)
			{
				_str[end + str_end] = _str[end];
				end--;
			}
			// ������������Ϊ֮�ճ����Ŀռ�
			for (int i = 0; i < str_end; i++)
			{
				_str[pos] = str[i];
				pos++;
			}
			// strncpy(_str+pos ,str, str_end);
			_size = _size + str_end;

			return *this;
		}
		void erase(size_t pos,size_t len = npos);
		size_t find(char ch, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		bool operator>(const char* str);
		bool operator>=(const char* str);
		bool operator<(const char* str);
		bool operator<=(const char* str);
		bool operator==(const char* str);

	private:
		char* _str;
		static size_t npos;
		size_t _size;		// ���е��ַ������ַ�����
		size_t _capacity;	// ��ǰ�ַ���������������Ч�ַ�������������'\0'
	};

	ostream& operator << (ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}

	void test_string1()
	{
		string s1;
		string s2("hello");

		cout << s2.c_str() << endl;
		cout << s2 << endl;

		// []���������
		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 1;
			cout << s2[i] << " ";
		}
		cout << endl;

		// ����������
		string::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			*it2 -= 1;
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;
		// ��Χfor
		// ��Χfor���ɵ�����֧�ֵģ�����δ������ջᱻ�������滻�ɵ������Ĵ���
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
	}
}