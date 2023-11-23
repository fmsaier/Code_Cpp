//HJ73 计算日期到天数转换
//
//描述
//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：O(n) ，空间复杂度：O(1)
//
//输入描述：
//输入一行，每行空格分割，分别是年，月，日
//
//输出描述：
//输出是这一年的第几天

#include <iostream>
using namespace std;


//int GetMonDay(int year, int month)
//{
//	int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//		day[2] = 29;
//	return day[month];
//}
//int main()
//{
//	int year = 0, month = 0, day = 0;
//	cin >> year >> month >> day;
//	if (year > 9999 || year < 1000 || month>12 || month < 1 || day > GetMonDay(year, month) || day < 1)
//	{
//		return 0;
//	}
//	int i = 1;
//	int _month = 1, _day = 1, _year = year;
//	while (_month != month || _day != day)
//	{
//		_day++;
//		if (_day > GetMonDay(_year, _month))
//		{
//			_month++;
//			_day = 1;
//		}
//		i++;
//	}
//	cout << i;
//	size_t a= 1;
//	return 0;
//}



//JZ64 求1 + 2 + 3 + ... + n
//
//描述
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//
//
//class Sum {
//public:
//    Sum()
//    {
//        _ret += _i;
//        _i++;
//    }
//    int GetRet()
//    {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n)
//    {
//        Sum sum[n];
//        return sum[n].GetRet();
//    }
//};



//int main()
//{
//	printf("%%");
//	return 0;
//}
//
//KY111 日期差值
//
//描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述：
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述：
//每组数据输出一行，即日期差值


//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int DayTab[2][13] = {
//    {0,31,28,31,30,31,30,31,31,30,31,30,31},
//    {0,31,29,31,30,31,30,31,31,30,31,30,31},
//};
//bool IsLeapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//int YearTab[2] = { 365,366 };
//int main() {
//    int year1, month1, day1;
//    int year2, month2, day2, minyear, maxyear;
//    int number, num1, num2;
//    while (scanf("%04d%02d%02d\n%04d%02d%02d", &year1, &month1, &day1, &year2, &month2, &day2) != EOF) {
//        number = 0;
//        minyear = year1 < year2 ? year1 : year2;
//        maxyear = (minyear == year1) ? year2 : year1;
//        while (minyear < maxyear) {
//            number += YearTab[IsLeapYear(minyear)];
//            ++minyear;
//        }
//        num1 = 0;
//        for (int i = 0; i < month1; ++i) {
//            num1 += DayTab[IsLeapYear(year1)][i];
//        }
//        num1 += day1;
//        num2 = 0;
//        for (int i = 0; i < month2; ++i) {
//            num2 += DayTab[IsLeapYear(year2)][i];
//        }
//        num2 += day2;
//        number += (year1 < year2 ? (num2 - num1 + 1) : (num1 - num2 + 1));
//        cout << number << endl;
//    }
//    return 0;
//}



//KY222 打印日期
//
//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。


//int GetMonDay(int _year, int _month)
//{
//	int mon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
//	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
//	{
//		return 29;
//	}
//	return mon[_month - 1];
//}
//int main()
//{
//	int year, day, month = 1;
//	while (cin >> year >> day)
//	{
//		month = 1;
//		while (day > GetMonDay(year, month))
//		{
//			day -= GetMonDay(year, month);
//			month++;
//		}
//		printf("%04d-%02d-%02d\n", year, month, day);
//	}
//	return 0;
//}




//KY258 日期累加
//
//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出。

//int GetMonDay(int _year, int _month)
//{
//	int mon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
//	if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
//	{
//		return 29;
//	}
//	return mon[_month - 1];
//}
//int main()
//{
//	int count = 0;
//	int year, month, day, addtion;
//	cin >> count;
//	while (count--)
//	{
//		cin >> year >> month >> day >> addtion;
//		day += addtion;
//		while (day > GetMonDay(year, month))
//		{
//			day -= GetMonDay(year, month);
//			month++;
//			if (month == 13)
//			{
//				year++;
//				month = 1;
//			}
//		}
//		printf("%04d-%02d-%02d\n", year, month, day);
//	}
//	return 0;
//}



//把字符串转换成整数
//
//描述
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为 0 或者字符串不是一个合法的数值则返回 0
//
//注意：
//①字符串中可能出现任意符号，出现除 + / -以外符号时直接输出 0
//②字符串中可能出现 + / -且仅可能出现在字符串首位。
//输入描述：
//输入一个字符串, 包括数字字母符号, 可以为空
//返回值描述：
//如果是合法的数值表达则返回该数字，否则返回0

int main()
{
	return 0;
}