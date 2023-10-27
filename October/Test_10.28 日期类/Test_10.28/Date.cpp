#include "Date.h"

//打印
void Date::Print()
{
	cout << _year << ":" << _month << ":" << _day << endl;
}

// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	return day[month];
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (year <= 0 || month <= 0 || day <= 0 || day > GetMonthDay(year, month))
	{
		cout << "数据非法" << endl;
	}
}

// 拷贝构造函数
// d2(d1)
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	if (this != &d) 
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

// 析构函数
Date::~Date()
{
	//?似乎不需要？
	//不处理最好（）
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	/*if (day < 0)
	{
		return *this -= (-day);
	}*/
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month >= 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}