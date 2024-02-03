#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

////17. 电话号码的字母组合
////
////给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
////
////给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//class Solution {
//public:
//    string s[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    void CatStringCombinations(vector<string>& v, int di, string catString, string& digits)
//    {
//        if (di == digits.size())
//        {
//            v.push_back(catString);
//            return;
//        }
//        int index = digits[di] - '0';
//        string str = s[index - 2];
//        for (int i = 0; i < str.size(); i++)
//        {
//            CatStringCombinations(v, di + 1, catString + str[i], digits);
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> v;
//        if (digits == "")
//            return v;
//        int di = 0;
//        string catString;
//        CatStringCombinations(v, di, catString, digits);
//        return v;
//    }
//};


//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i + 3 < nums.size(); i+=3)
//        {
//            if (nums[i] != nums[i + 2])
//            {
//                return nums[i];
//            }
//        }
//        return nums[nums.size() - 1];
//    }
//};


//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums) {
//        vector<int> v;
//        sort(nums.begin(), nums.end());
//        int i = 0;
//        while (i + 2 < nums.size())
//        {
//            if (nums[i] != nums[i + 1])
//            {
//                v.push_back(nums[i]);
//                i++;
//                continue;
//            }
//            i += 2;
//        }
//        if (v.size() == 1)
//            v.push_back(nums[nums.size() - 1]);
//        if (v.size() == 0)
//        {
//            v.push_back(nums[nums.size() - 1]);
//            v.push_back(nums[nums.size() - 2]);
//        }
//        return v;
//    }
//};

//左是/2 右是-1/2

//class LCA {
//public:
//    int getLCA(int a, int b) {
//        vector<int> v;
//        while (a != 1)
//        {
//            v.push_back(a);
//            a /= 2;
//        }
//        v.push_back(1);
//        while (b != 1)
//        {
//            v.push_back(b);
//            b /= 2;
//        }
//        v.push_back(1);
//        sort(v.begin(), v.end());
//        vector<int>::reverse_iterator it = v.rbegin();
//        while (it != v.rend())
//        {
//            if (*it == *(it + 1))
//                return *it;
//            it++;
//        }
//        return 1;
//    }
//};



void ToTwo(int a, vector<int>& v)
{
	int b = 0;
	int c = 0;
	while (a > 1)
	{
		b = a / 2;
		c = a - b * 2;
		a = b;
		v.push_back(c);
	}
	v.push_back(a);
}
int main()
{
	int a;
	cin >> a;
	vector<int> v;
	int count = 0;
	int sum = 0;
	ToTwo(a, v);
	for (int i : v)
	{
		if (i == 1)
		{
			count++;
		}
		if (i == 0)
		{
			if(count >= sum)
				sum = count;
			count = 0;
		}
	}
	if (count >= sum)
		sum = count;
	cout << sum;
}

// 64 位输出请用 printf("%lld")