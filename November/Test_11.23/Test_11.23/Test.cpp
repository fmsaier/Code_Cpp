#include <iostream>
#include <string>
#include <vector>
using namespace std;


//把字符串转换成整数
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
// 
// 
//class Solution {
//public:
//    int StrToInt(string str) {
//        int a = 0;
//        int sum = 0;
//        int n = 1;
//        bool isSymbol = false;
//        bool isNeg = false;
//        cin >> str;
//        string::reverse_iterator it = str.rbegin();
//        if (*(str.rend() - 1) == '+')
//            isSymbol = true;
//        if (*(str.rend() - 1) == '-')
//        {
//            isSymbol = true;
//            isNeg = true;
//        }
//
//        while (it != str.rend())
//        {
//            if (isSymbol && (it + 1) == str.rend())
//                break;
//            if (*it > '9' || *it < '0')
//                return 0;
//            a = *it - 48;
//            sum += a * n;
//            n *= 10;
//            it++;
//        }
//        if (isNeg)
//            sum = -sum;
//        return sum;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.StrToInt("0") << endl;
//}


//344. 反转字符串
//
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//
//示例 1：
//
//输入：s = ["h", "e", "l", "l", "o"]
//输出：["o", "l", "l", "e", "h"]
//示例 2：
//
//输入：s = ["H", "a", "n", "n", "a", "h"]
//输出：["h", "a", "n", "n", "a", "H"]

//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        reverse(s.begin(), s.end());
//    }
//};
//?


//387. 字符串中的第一个唯一字符
//
//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1 。
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int* chararr = new int[26] {0};
//        char ch = '\0';
//        string::iterator it = s.begin();
//        while (it != s.end())
//        {
//            chararr[*it - 'a']++;
//            it++;
//        }
//        for (int i = 0; i < s.size(); i++)
//        {
//            ch = s[i];
//            if (chararr[ch - 'a'] == 1)
//                return i;
//        }
//        return -1;
//    }
//};

//int main()
//{
//	string a = "hello world";
//	string b = a;
//	if (a.c_str() == b.c_str())
//		cout << "true" << endl;
//	else 
//		cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//		cout << "true" << endl;
//	else 
//		cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//		cout << "true" << endl;
//	else 
//		cout << "false" << endl;
//	return 0;
//}
// 
// 
// 
//int main()
//{
//	string str("Hello Bit.");
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}



//int main()
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//
//	int size_pos = 0;
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}




//415. 字符串相加
//
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int next = 0;   
//        int ret = 0;
//        auto it1 = num1.rbegin();
//        auto it2 = num2.rbegin();
//        int ret1 = *it1 - '0';
//        int ret2 = *it2 - '0';
//        string sum;
//        while (it1 != num1.rend() || it2 != num2.rend())
//        { 
//            ret = ret1 + ret2 + next;
//            next = ret / 10;
//            ret = ret % 10;
//            sum += ret + '0';
//            if(it1 != num1.rend())
//                it1++;
//            if(it2 != num2.rend())
//                it2++;
//            if (it1 == num1.rend())
//                ret1 = 0;
//            else
//            {
//                ret1 = *it1 - '0';
//            }           
//            if (it2 == num2.rend())
//                ret2 = 0;
//            else
//            {
//                ret2 = *it2 - '0';
//            }          
//        }
//        if (next != 0)
//            sum += next + '0';
//        reverse(sum.begin(), sum.end());
//        return sum;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.addStrings("1", "9") << endl;
//}



//125. 验证回文串
//
//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//
//字母和数字都属于字母数字字符。
//
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        string strReverse;
//        string::iterator it = s.begin();
//        while (it != s.end())
//        {
//            if (isalpha(*it) || isdigit(*it))
//            {
//                if (islower(*it))
//                    strReverse += *it;
//                else
//                    strReverse += *it - ('A' - 'a');
//            }     
//            it++;
//        }
//        s = strReverse;
//        reverse(strReverse.begin(), strReverse.end());
//        cout << strReverse << endl;
//        cout << s << endl;
//        if (strcmp(s.c_str(), strReverse.c_str()) == 0)
//            return true;
//        else
//            return false;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.isPalindrome("0P") << endl;
//    //cout << strcmp("op", "po") << endl;
//}



//541. 反转字符串 II
//给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int prev = 0;
//        int cur = 0;
//        int count = k;
//        while (cur < s.size())
//        {
//            while (count--)
//            {
//                cur += 2;
//                prev = cur - k;
//            }
//            count = k;
//            if (cur <= s.size())
//            {
//                reverse(s.begin() + prev - k, s.begin() + prev);
//            }
//            else if (cur > s.size() && prev <= s.size())
//            {
//                reverse(s.begin() + prev - k, s.begin() + prev);
//            }
//            else if (prev > s.size())
//            {
//                reverse(s.begin() + cur - 2 * k, s.end());
//            }
//        }
//        return s;
//    }
//};
//int main()
//{
//    Solution s;
//    s.reverseStr("abcd", 4);
//    return 0;
//}




//557. 反转字符串中的单词 III
//
//给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//class Solution {
//public:
//    string reverseWords(string s) {
//        int pos1 = 0;
//        int pos2 = s.find(" ");
//        string::iterator it = s.begin();
//        while (pos2 != string::npos && it + pos2 != s.end())
//        {
//            reverse(s.begin() + pos1, s.begin() + pos2);
//            pos1 = pos2 + 1;
//            pos2 = s.find(" ", pos1);
//        }
//        reverse(s.begin() + pos1, s.end());
//        return s;
//    }
//};
//int main()
//{
//    Solution s;
//    cout << s.reverseWords("Let's take LeetCode contest") << endl;
//    return 0;
//}



//43. 字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。



//HJ1 字符串最后一个单词的长度
//描述
//计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
//输入描述：
//输入一行，代表要计算的字符串，非空，长度小于5000。
//
//输出描述：
//输出一个整数，表示输入字符串最后一个单词的长度。
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string s;
//    getline(cin, s);
//    int pos = s.rfind(" ");
//    if (pos != s.npos)
//    {
//        cout << s.size() - pos - 1;
//    }
//    else
//    {
//        cout << s.size();
//    }
//    return 0;
//}


int main()
{
	string s("Hello");
	char c = s.operator[](1);
	cout << s << endl;
	c = 'a';
	cout << s << endl;
}