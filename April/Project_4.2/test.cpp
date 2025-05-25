#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <unordered_set>
#include <unordered_map>
#include <memory>
using namespace std;
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	//future<int> res = async(launch::async, Add, 11, 22);  //异步创建线程执行任务
//	//cout << res.get() << endl; //阻塞式获取结果
//
//	//封装对象
//	packaged_task<int(int, int)> task(Add);
//	//获取任务包关联的future对象
//	future<int> res = task.get_future();
//	//执行函数
//	thread thd([&]() 
//		{
//			task(11, 22);
//		});
//	//获取结果
//	cout << res.get() << endl;
//	thd.join();
//	return 0;
//}

//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target)
//    {
//        int tmp = 0;
//        sort(nums.begin(), nums.end());
//        int d = nums.size() - 1, c = d - 1, b = c - 1, a = 0;
//        vector<vector<int>> ret;
//        while (d > 2)
//        {
//            if (d != nums.size() - 1 && nums[d] == nums[d + 1])
//            {
//                d--;
//                c = d - 1;
//                b = c - 1;
//                a = 0;
//                continue;
//            }
//            while (c > 1)
//            {
//                //d每次进来是不一样的，我要保证这层循环内c的唯一性，每次d刚进来唯一性不用管
//                //记录上一次的d
//                if (tmp == nums[d] && c != nums.size() - 2 && nums[c] == nums[c + 1])
//                {
//                    c--;
//                    b = c - 1;
//                    a = 0;
//                    continue;
//                }
//                else if (tmp != nums[d])
//                    tmp = nums[d];
//
//                while (a < b)
//                {
//                    if ((long long)nums[a] + nums[b] + nums[c] + nums[d] < target)
//                        a++;
//                    else if ((long long)nums[a] + nums[b] + nums[c] + nums[d] > target)
//                        b--;
//                    else
//                    {
//                        if (a == 0 || nums[a] != nums[a - 1])
//                            ret.push_back({ nums[a], nums[b], nums[c], nums[d] });
//                        a++;
//                    }
//                }
//                c--;
//                b = c - 1;
//                a = 0;
//            }
//            d--;
//            c = d - 1;
//            b = c - 1;
//            a = 0;
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x)
//    {
//        int sum = 0;
//        for (int& n : nums)
//        {
//            sum += n;
//        }
//        int target = sum - x;
//        if (target <= 0) return -1;
//        sum = 0;
//        int left = 0, right = 0, len = 0;
//        while (right < nums.size())
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                if (sum == target)
//                    len = max(len, right - left + 1);
//                sum -= nums[left++];
//            }
//            right++;
//        }
//        return len == 0 ? -1 : nums.size() - len;
//    }
//};
//
//class A
//{
//
//};
//class B : public A 
//{
//public:
//    void Test()
//    {
//        cout << "????? " << endl;
//    }
//};
//
//
//vector<int> findAnagrams(string s, string p) {
//    //unordered_map<char, int> hashs, hashp;
//    int count = 0;
//    int hashs[26] = { 0 };
//    int hashp[26] = { 0 };
//    for (auto ch : p)
//    {
//        hashp[ch - 'a']++;
//    }
//    int left = 0;
//    int right = 0;
//    vector<int> v;
//    while (right < s.size())
//    {
//        hashs[s[right] - 'a']++;
//        if (hashs[s[right] - 'a'] <= hashp[s[right] - 'a'])
//            count++;
//        if (right - left + 1 > p.size())
//        {
//            hashs[s[left] - 'a']--;
//            if (hashs[s[left] - 'a'] < hashp[s[left] - 'a'])
//                count--;
//
//            left++;
//        }
//        if (right - left + 1 == p.size())
//        {
//            //int isRight = 1;
//            //for (int i = 0; i < 26; i++)
//            //{
//            //    if (hashs[i] != hashp[i])
//            //    {
//            //        isRight = 0;
//            //        break;
//            //    }
//            //}
//            if (count == p.size())
//                v.push_back(left);
//        }
//        right++;
//    }
//    return v;
//}


//class Solution {
//public:
//    string minWindow(string s, string t)
//    {
//        int count = 0;
//        unordered_map<char, int> hash1, hash2;
//        for (char ch : t)
//        {
//            hash2[ch]++;
//        }
//        int left = 0, right = 0;
//        int minLeft = 0, len = INT_MAX;
//        while (right < s.size())
//        {
//            hash1[s[right]]++;
//            if (hash2.find(s[right]) != hash2.end() && hash1[s[right]] <= hash2[s[right]])
//                count++;
//            while (count == t.size())
//            {
//                hash1[s[left]]--;
//                if (hash2.find(s[left]) != hash2.end() && hash1[s[left]] < hash2[s[left]])
//                {
//                    count--;
//                    len = min(len, right - left + 1);
//                    len == right - left + 1 ? minLeft = left : minLeft = minLeft;
//                }
//                left++;
//            }
//            right++;
//        }
//        return len == INT_MAX ? "" : string(s.begin() + minLeft, s.begin() + minLeft + len);
//    }
//};

//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target)
//                left = mid + 1;
//            else right = mid;
//        }
//        return left;
//    }
//};
//
//class A
//{
//public:
//
//};
//
//class B : public A
//{
//
//};
//
//using ptrA = shared_ptr<A>;
//using ptrB = shared_ptr<B>;
//
//void Test(ptrA a)
//{
//    cout << "Test(A a) " << endl;
//}
//
//void Test(ptrA a, int b)
//{
//
//}

int main()
{
    

    return 0;
}
