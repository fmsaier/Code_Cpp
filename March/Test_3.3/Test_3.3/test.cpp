//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() 
//{
//    string s1, s2;
//    getline(cin, s1);
//    getline(cin, s2);
//    int i = 0;
//    for (int j = 0;j<s2.size();j++)
//    {
//        if (s1[i] == '?' && (isalpha(s2[j]) || isdigit(s2[j])))
//        {
//            i++;
//            continue;
//        }
//        if (s1[i] == '*' && (isalpha(s2[j]) || isdigit(s2[j])))
//        {
//            while()
//        }
//        if (s2[j] != s1[i])
//        {
//            cout << false << endl;
//            break;
//        }
//    }
//}
//// 64 位输出请用 printf("%lld")

//
//#include <iostream>
//using namespace std;
//
//int Fib(int n)
//{
//    if (n <= 2)
//        return 1;
//
//    int f, f1 = 1, f2 = 1;
//    for (int i = 3; i <= n; i++)
//    {
//        f = f1 + f2;
//        f1 = f2;
//        f2 = f;
//
//    }
//    return f;
//}
//
//int main() {
//    int month, sum = 0;
//    while (cin >> month)
//    {
//        sum = Fib(month);
//        cout << sum << endl;
//
//    }
//    return 0;
//}
//// 64 位输出请用 printf("%lld")




//#include <iostream>
//#include <string>
//#include <stdint.h>
//using namespace std;
//bool match(const char* pattern, const char* str)
//{
//	//当前字符结束，返回true
//	if (*pattern == '\0' && *str == '\0')
//		return true;
//	//两个字符串有一个先结束，则返回false
//	if (*pattern == '\0' || *str == '\0')
//		return false;
//	if (*pattern == '?')
//	{
//		//新增用例，题目强调?只能够匹配数字和字母，所以增加新的判断
//		if (!isdigit(*str) && !isalpha(*str))
//			return false;
//		//遇到?号，匹配一个字符，跳过一个位置
//		return match(pattern + 1, str + 1);
//	}
//	else if (*pattern == '*')
//	{
//		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
//		while (*pattern == '*')
//		{
//			pattern++;
//		} pattern--;
//		if (!isdigit(*str) && !isalpha(*str))
//			return match(pattern + 1, str);
//		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
//	}
//	else if (tolower(*pattern) == tolower(*str)) //忽略大小写
//	{
//		//如果当前字符相等，匹配下一个字符
//		return match(pattern + 1, str + 1);
//	}
//	return false;
//}
//int main()
//{
//	string pattern, str;
//	while (cin >> pattern >> str)
//	{
//		bool ret = match(pattern.c_str(), str.c_str());
//		if (ret)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//	}
//	return 0;
//}
