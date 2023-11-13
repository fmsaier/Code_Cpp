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



int main()
{
	printf("%%");
	return 0;
}