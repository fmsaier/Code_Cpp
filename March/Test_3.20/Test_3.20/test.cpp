#include <iostream>

using namespace std;

//template<class T>
//class A
//{
//	T a;
//};
//template<class T>
//class B
//{
//	typedef A<T> Node;
//	Node b;
//};
//
//int main()
//{
//	return 0;
//}

#include <vector>
#include <string>
#include <unordered_map>

//可能字符串有错位，那就按照words的每一个string的size去多次滑动窗口就行了

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string, int> hashp;
        for (const auto& str : words)
        {
            hashp[str]++;
        }
        int right = 0, left = 0;
        int count = 0;
        int n = words[0].size();
        int k = n;
        vector<int> v;
        while (k--)
        {
            right = k;
            left = k;
            count = 0;
            unordered_map<string, int> hashs;
            //后面错位了，要用right+n构造string的end，end是左闭右开，所以=是可以的
            while (right + n <= s.size())
            {
                string tmp(s.begin() + right, s.begin() + right + n);
                hashs[tmp]++;
                if (hashp.count(tmp) && hashs[tmp] <= hashp[tmp])
                    count++;
                if ((right - left + n) / n > words.size())
                {
                    tmp = string(s.begin() + left, s.begin() + left + n);
                    if (hashp.count(tmp) && hashs[tmp] <= hashp[tmp])
                        count--;
                    hashs[tmp]--;
     /*               if (hashs[tmp] == 0)
                        hashs.erase(tmp);*/
                    left += n;
                }
                /*if (hashs.size() == hashp.size())
                {
                    if (count == words.size())
                        v.push_back(left);
                }*/
                if (count == words.size())
                    v.push_back(left);
                right += n;
            }
        }
    
        return v;
    }
};

//class Solution
//{
//public:
//	vector<int> findSubstring(string s, vector<string>& words)
//	{
//		vector<int> ret;
//		unordered_map<string, int> hash1; // 保存 words ⾥⾯所有单词的频次
//		for (auto& s : words) hash1[s]++;
//		int len = words[0].size(), m = words.size();
//		for (int i = 0; i < len; i++) // 执⾏ len 次
//		{
//			unordered_map<string, int> hash2; // 维护窗⼝内单词的频次
//			for (int left = i, right = i, count = 0; right + len <= s.size();
//				right += len)
//			{
//				 进窗⼝ + 维护 count
//				string in = s.substr(right, len);
//				hash2[in]++;
//				if (hash1.count(in) && hash2[in] <= hash1[in]) count++;
//				 判断
//				if (right - left + 1 > len * m)
//				{
//					 出窗⼝ + 维护 count
//					string out = s.substr(left, len);
//					if (hash1.count(out) && hash2[out] <= hash1[out]) count--;
//					hash2[out]--;
//					left += len;
//				}
//				 更新结果
//				if (count == m) ret.push_back(left);
//			}
//		}
//		return ret;
//	}
//};


int main()
{
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = { "foo","bar" };
    s.findSubstring(str, words);
    return 0;
}