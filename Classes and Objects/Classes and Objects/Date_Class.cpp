#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// 实现一个完善的日期类
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
			return;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	inline bool operator == (const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator > (const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;

		return false;
	}
	bool operator>=(const Date& d)
	{
		return *this == d || *this > d;
	}
	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	Date& operator+=(int day)
	{
		*this = *this + day;

		return *this;
	}

	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	int operator-(const Date& d) const
	{
		int flag = 1;
		Date min = d;
		Date max = *this;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return flag * n;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};



//int main()
//{
//	Date d1(2030, 5, 29);
//	d1.Print();
//
//	Date d2(d1);
//	d2.Print();
//
//	Date d3 = d1 + 1000;
//	d3.Print();
//
//	cout << d1 - d3 << endl;
//	cout << d3 - d1 << endl;
//	return 0;
//}