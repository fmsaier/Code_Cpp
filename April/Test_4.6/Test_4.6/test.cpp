#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	void Insert(int* s, char ch)
//	{
//		if (ch - 'a' < 0)
//		{
//			++s[ch - 'A'];
//		}
//		else
//		{
//			++s[ch - 'a' + 26];
//		}
//	}
//	size_t Index(char ch)
//	{
//		if (ch - 'a' < 0)
//		{
//			return (ch - 'A');
//		}
//		else
//		{
//			return (ch - 'a' + 26);
//		}
//	}
//	string minWindow(string s, string t)
//	{
//		if (t.size() == 1)
//		{
//			for (char var : s)
//			{
//				if (var == t[0])
//					return t;			
//			}
//			return "";
//		}
//		int hashs[52] = { 0 };
//		int hasht[52] = { 0 };
//		//unordered_map<char, int> hasht, hashs;
//		for (char var : t)
//		{
//			Insert(hasht, var);
//		}
//		size_t count = 0;
//		int minLeft = -1;
//		size_t right = 0, left = 0;
//		size_t len = INT_MAX;
//		bool isOK = false;
//		//AABC
//		//left到下一个有效且count!=size
//		while (right < s.size())
//		{
//			//在t中存在
//			if (hasht[Index(s[right])])
//			{			
//				//s中的数量少于t的数量
//				if(hashs[Index(s[right])] < hasht[Index(s[right])])
//					count++;
//				hashs[Index(s[right])]++;
//				if (count == 1 && !isOK)
//				{
//					left = right;
//					isOK = true;
//				}
//
//			}
//			//找到此时的最小有效字符串
//			while (count == t.size())
//			{
//				size_t tmp = len;
//				len = min(len, right - left + 1);
//				if (len != tmp)
//				{
//					minLeft = left;
//				}
//				if (hasht[Index(s[left])])
//					hashs[Index(s[left])]--;
//				//s中的数量少于t的数量
//				if (hashs[Index(s[left])] < hasht[Index(s[left])])
//					count--;
//				left++;
//				//哈希的count返回的是k
//				//cout << (hasht.count(s[left]) == 0) << endl;
//				//cout << (hashs[s[left]] > hasht[s[left]]) << endl;
//				//这里需要的是v
//				//让left找到下一个有效数据
//				while ((hasht[Index(s[left])] == 0) || (hashs[Index(s[left])] > hasht[Index(s[left])]))
//				{
//					if (hashs[Index(s[left])] > hasht[Index(s[left])])
//						hashs[Index(s[left])]--;
//					left++;
//				}
//			}
//			right++;
//		}
//		if (minLeft == -1)
//			return "";
//		string ret(s.begin() + minLeft, s.begin() + minLeft + len);
//		return ret;
//	}
//};
//
//int main()
//{
//	Solution test;
//	string s = "a";
//	string t = "aa";
//	cout << 'A' << 'a' << endl;
//	cout << test.minWindow(s, t) << endl;
//	cout << (1 || 0);
//	return 0;
//}



//class A
//{
//public:
//	virtual void Test()
//	{
//
//	}
//	int _a;
//};
//class B : virtual public A
//{
//	int _b;
//	virtual void TestB()
//	{
//
//	}
//};
//class C : virtual public A
//{
//	virtual void TestC()
//	{
//
//	}
//};
//class D :public B, public C
//{
//
//};
//static void Test()
//{
//
//}
//
//#include <functional>
//
//int main()
//{
//	//cout << sizeof(B) << endl;
//	int c = 0;
//	//A a;
//	//B b;
//	//C c;
//	//D d;
//	auto pf = [=](int a, int b) mutable {a++; c++; return a; };
//	cout << pf(1, 2);
//	//cout << sizeof(long) << endl;
//	function<int(int, int)> f = pf;
//	cout << f(1, 2);
//	Solution s;
//	function<void(A)> f1 = &A::Test;
//	f1(A());
//	function<void()> f = Test;
//    vector<int> v = { -1,0,3,5,9,12 };
//   // cout << s.search(v, 2);
//    return 0;
//}




//
//class Solution {
//public:
//	int search(vector<int>& nums, int target)
//	{
//		int left = 0;
//		int right = nums.size() - 1;
//		int mid = left + (right - left) / 2;
//		while (left <= right)
//		{
//			if (nums[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else if (nums[mid] < target)
//			{
//				left = mid + 1;
//			}
//			else
//				return mid;
//			mid = left + (right - left) / 2;
//		}
//		return -1;
//	}
//};



//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) 
//    {
//        vector<int> v = { -1,-1 };
//        if (nums.size() == 0)
//            return v;
//        int left = 0;
//        int right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid;
//            }
//        }
//        if (nums[right] != target)
//            return v;
//        v[0] = right;
//        left = 0;
//        right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (nums[mid] <= target)
//            {
//                left = mid;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//        v[1] = left;
//        return v;
//    }
//};

//int main()
//{
//    Solution s;
//
//    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
//    s.searchRange(nums, 8);
//}



//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) 
//    {
//        int left = 0, right = nums.size() - 1;
//        //朴素
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target)
//                left = mid + 1;
//            else if (nums[mid] > target)
//                right = mid - 1;
//            else
//                return mid;
//        }
//        return left;
//    }
//};



//class Solution {
//public:
//	int mySqrt(int x)
//	{
//		int left = 0, right = x;
//		while (left <= right)
//		{
//			long long mid = left + (right - left) / 2;
//			if (mid * mid < x)
//				left = mid + 1;
//			else if (mid * mid > x)
//				right = mid - 1;
//			else
//				return mid;
//		}
//		return right;
//	}
//};




//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr)
//	{
//		int left = 0, right = arr.size() - 1;
//		//朴素
//		while (left <= right)
//		{
//			int mid = left + (right - left) / 2;
//			if (arr[mid] < arr[mid + 1])
//				left = mid + 1;
//			else if (arr[mid] < arr[mid - 1])
//				right = mid - 1;
//			else
//				return mid;
//		}
//		return left;
//	}
//};
//
//int main()
//{
//	vector<int> arr = { 24,69,100,99,79,78,67,36,26,19 };
//	Solution s;
//	cout << s.peakIndexInMountainArray(arr);
//	return 0;
//}



//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		if (nums[0] < nums[nums.size() - 1])
//			return nums[0];
//		int left = 0;
//		int right = nums.size() - 1;
//		//左边界的二分
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			if (nums[mid] > nums[nums.size() - 1])
//				left = mid + 1;
//			else if (nums[mid] <= nums[nums.size() - 1])
//				right = mid;
//		}
//		return nums[left];
//
//	}
//};
//
//int main()
//{
//	vector<int> nums = { 2,1 };
//	Solution s;
//	cout << s.findMin(nums);
//	return 0;
//}
//class Solution {
//public:
//	int takeAttendance(vector<int>& records)
//	{
//		int left = 0, right = records.size() - 1;
//		//左边界的二分
//		while (left < right)
//		{
//			int mid = left + (right - left) / 2;
//			if (records[mid] == mid)
//				left = mid + 1;
//			else if (records[mid] > mid)
//				right = mid;
//		}
//		//左边界的二分出来在判断一下
//		if (records[left] == left)
//			return left + 1;
//		return left;
//	}
//};

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else if (nums[mid] < nums[mid - 1])
                right = right - 1;
            else
                return mid;
        }
        return left;
    }
};