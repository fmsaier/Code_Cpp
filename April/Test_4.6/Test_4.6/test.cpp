#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	void Insert(int* s, char ch)
	{
		if (ch - 'a' < 0)
		{
			++s[ch - 'A'];
		}
		else
		{
			++s[ch - 'a' + 26];
		}
	}
	size_t Index(char ch)
	{
		if (ch - 'a' < 0)
		{
			return (ch - 'A');
		}
		else
		{
			return (ch - 'a' + 26);
		}
	}
	string minWindow(string s, string t)
	{
		if (t.size() == 1)
		{
			for (char var : s)
			{
				if (var == t[0])
					return t;			
			}
			return "";
		}
		int hashs[52] = { 0 };
		int hasht[52] = { 0 };
		//unordered_map<char, int> hasht, hashs;
		for (char var : t)
		{
			Insert(hasht, var);
		}
		size_t count = 0;
		int minLeft = -1;
		size_t right = 0, left = 0;
		size_t len = INT_MAX;
		bool isOK = false;
		//AABC
		//left到下一个有效且count!=size
		while (right < s.size())
		{
			//在t中存在
			if (hasht[Index(s[right])])
			{			
				//s中的数量少于t的数量
				if(hashs[Index(s[right])] < hasht[Index(s[right])])
					count++;
				hashs[Index(s[right])]++;
				if (count == 1 && !isOK)
				{
					left = right;
					isOK = true;
				}

			}
			//找到此时的最小有效字符串
			while (count == t.size())
			{
				size_t tmp = len;
				len = min(len, right - left + 1);
				if (len != tmp)
				{
					minLeft = left;
				}
				if (hasht[Index(s[left])])
					hashs[Index(s[left])]--;
				//s中的数量少于t的数量
				if (hashs[Index(s[left])] < hasht[Index(s[left])])
					count--;
				left++;
				//哈希的count返回的是k
				//cout << (hasht.count(s[left]) == 0) << endl;
				//cout << (hashs[s[left]] > hasht[s[left]]) << endl;
				//这里需要的是v
				//让left找到下一个有效数据
				while ((hasht[Index(s[left])] == 0) || (hashs[Index(s[left])] > hasht[Index(s[left])]))
				{
					if (hashs[Index(s[left])] > hasht[Index(s[left])])
						hashs[Index(s[left])]--;
					left++;
				}
			}
			right++;
		}
		if (minLeft == -1)
			return "";
		string ret(s.begin() + minLeft, s.begin() + minLeft + len);
		return ret;
	}
};

int main()
{
	Solution test;
	string s = "a";
	string t = "aa";
	cout << 'A' << 'a' << endl;
	cout << test.minWindow(s, t) << endl;
	cout << (1 || 0);
	return 0;
}