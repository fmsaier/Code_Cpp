#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x)
//    {
//        long long sum = 0;
//        for (auto i : nums)
//        {
//            sum += i;
//        }
//        if (sum == x)
//            return nums.size();
//        long long target = sum - x;
//        if (target < 0)
//            return -1;
//        int left = 0;
//        int right = 0;
//        int len = 0;
//        sum = nums[0];
//        while (right < nums.size())
//        {
//            if (sum < target)
//            {
//                right++;
//                sum += nums[right];
//
//            }
//            else if (sum > target)
//            {
//                sum -= nums[left];
//                left++;
//            }
//            else
//            {
//                len = max(len, right - left + 1);
//                right++;
//                if (right >= nums.size())
//                    break;
//                sum += nums[right];
//            }
//        }
//        if (len == 0)
//            return -1;
//        else
//            return nums.size() - len;
//    }
//};
//
//
//int main()
//{
//    Solution s;
//    vector<int> v = { 1,1,1,1 };
//    cout << s.minOperations(v, 4);
//    return 0;
//}



//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) 
//    {
//        int left = 0;
//        int right = 0;
//        int range1 = fruits[0];
//        int range2 = -1;
//        int n = 1;
//        int len = 0;
//        while (right < fruits.size())
//        {
//            if (n <= 2)
//            {
//                len = max(len, right - left + 1);
//                right++;
//                if (right >= fruits.size())
//                    break;
//                if (fruits[right] != range1 && fruits[right] != range2 && n == 2)
//                {
//                    n++;
//                    continue;
//                }
//                if (fruits[right] != range1 && fruits[right] != range2)
//                {
//                    if (fruits[left] == range1)
//                        range2 = fruits[right];
//                    else
//                        range1 = fruits[right];
//                    n++;
//                }
//            }
//            else if (n > 2)
//            {
//                int tmp1 = right;
//                int tmp2 = right;
//                while (fruits[tmp1] != range1)
//                {
//                    tmp1--;
//                }
//                while (fruits[tmp2] != range2)
//                    tmp2--;
//                left = min(tmp1, tmp2) + 1;
//                range1 = fruits[left];
//                range2 = fruits[right];
//                n--;
//            }
//        }
//        return len;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> v = { 0,1,2,2 };
//    cout << s.totalFruit(v);
//    return 0;
//}

#include <unordered_map>

//class Solution {
//public:
//	int totalFruit(vector<int>& fruits)
//	{
//		unordered_map<int, int> hash;
//		int left = 0;
//		int right = 0;
//		int len = 0;
//		while (right < fruits.size())
//		{
//			hash[fruits[right]]++;
//			if (hash.size() > 2)
//			{
//				hash[fruits[left]]--;
//				if (hash[fruits[left]] == 0)
//					hash.erase(fruits[left]);
//				left++;
//			}
//			len = max(len, right - left + 1);
//			right++;
//		}
//		return len;
//	}
//};

class Solution {
public:
	int totalFruit(vector<int>& fruits)
	{
		unordered_map<int, int> hash;
		int left = 0;
		int right = 0;
		int len = 0;
		while (right < fruits.size())
		{
			hash[fruits[right]]++;

			if (hash.size() > 2)
			{
				hash[fruits[left]]--;
				if (hash[fruits[left]] == 0)
					hash.erase(fruits[left]);
				left++;
			}

			len = max(len, right - left + 1);

			right++;

		}
		return len;
	}
};

//class Solution
//{
//public:
//	int totalFruit(vector<int>& f)
//	{
//		unordered_map<int, int> hash; // 统计窗⼝内出现了多少种⽔果
//		int ret = 0;
//		for (int left = 0, right = 0; right < f.size(); right++)
//		{
//			hash[f[right]]++; // 进窗⼝
//			while (hash.size() > 2) // 判断
//			{
//
//				hash[f[left]]--;
//				if (hash[f[left]] == 0)
//					hash.erase(f[left]);
//				left++;
//			}
//			ret = max(ret, right - left + 1);
//		}
//		return ret;
//	}
//};


int main()
{
    Solution s;
    vector<int> v = { 3,3,3,1,2,1,1,2,3,3,4 };
    cout << s.totalFruit(v);
    return 0;
}