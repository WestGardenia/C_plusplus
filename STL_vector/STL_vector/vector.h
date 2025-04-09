#pragma once
#include<iostream>
#include<string>
#include<cassert>

using namespace std;

namespace Dawn
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		vector(const vector<T>& v)
		{
			//_start = new T[v.capacity()];
			//_finish = _start;
			//_endofstorage = _start + v.capacity();

			//for (size_t i = 0; i < v.size(); i++)
			//{
			//	*_finish = v[i];
			//	_finish++;
			//}

			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}

		size_t capacity()	const
		{
			return _endofstorage - _start;
		}

		size_t size()	const
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * sz);		--->	��δ��������test_vector5()
					//
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void pop_back()
		{
			assert(_start < _finish);
			_finish--;
		}

		void insert(iterator pos, const T& x)
		{
			// ��posλ�ò�������
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);

				// �������ԭ���ĵ������ͻ�ʧЧ������Ҫ���¼����µĿռ��е�����
				pos = _start + n;
			}
			iterator end = _finish -1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;

			return pos;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)	const
		{
			assert(i < size());
			return _start[i];
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = (capacity() == 0 ? 2 : capacity() * 2);
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}

		void swap(vector<T>& v1, vector<T>& v2)
		{
			::swap(v1._start, v2._start);
			::swap(v1._finish, v2._finish);
			::swap(v1._endofstorage, v2._endofstorage);
		}

		vector<T>& operator=(vector<T> v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				_finish = _start;
				for (size_t i = 0; i < v.size(); i++)
				{
					*_finish = v[i];
					_finish++;
				}
			}
			return *this;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{

			cout << *it << " ";
			it++;
		}
		cout << endl;
	}


	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;
		while (it != v.end())
		{
			*it += 1;
			cout << *it << " ";
			it++;
		}
		cout << endl;
		for (auto& e : v)
		{
			e -= 1;
			cout << e << " ";
		}
		cout << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int>::iterator it = v.begin();
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		v.insert(v.begin() + 1, 3);
		v.insert(v.begin() + 1, 3);
		v.insert(v.begin() + 1, 3);
		print_vector(v);

		it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
		print_vector(v);
	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		print_vector(v);
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;

		v.resize(3, 3);
		print_vector(v);
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;
		v.resize(7, 7);
		print_vector(v);
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;
		v.resize(18, 18);
		print_vector(v);
		cout << "v�д��е����ݸ��� " << v.size() << endl;
		cout << "v�пɴ�ŵ����ݸ���" << v.capacity() << endl;
	}
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		print_vector(v);

		vector<int> v1(v);
		print_vector(v1);

		vector<int> v2 = v1;
		print_vector(v2);

		vector<int> v4;
		v4.push_back(10);
		v4.push_back(20);
		v4.push_back(30);
		v4.push_back(40);

		swap(v1, v4);

		print_vector(v1);

	}
	void test_vector5()
	{

		// ��δ�������⣺
		// �ڹ��캯��ʵ�ֹ����У�memcpy������string���󿽱����¿��ٵ�tmp�У��ٽ��ֲ������е�_start��string�����еĿռ��ͷ�
		// ����string�б������_strָ�룬���ָ����Ȼָ����ԭ����string�Ŀռ�
		// �ͻ�������ֵ
		// 
		// �������ı�������vector����Ȼʹ�������
		//				������string��û��ʹ�����
		// 
		// �����ڹ��캯���е�reserve������Ӧ��ֱ���ø�ֵ
		//
		vector<string> v;
		v.push_back("11111111");
		v.push_back("22222222");
		v.push_back("33333333");
		v.push_back("44444444");
		v.push_back("55555555");

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

