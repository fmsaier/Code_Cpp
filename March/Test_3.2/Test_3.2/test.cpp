////#include<iostream>
////#include<string>
////using namespace std;
////int main()
////{
////    int n;
////    int a[] = { 4,2,3,2 };
////    while (cin >> n)
////    {
////        int ret = -1;
////        if (n > 2) {
////            ret = a[(n - 2) % 4];
////        }
////        cout << ret << endl;
////    }
////    return 0;
////}
//
//
//
//
////#include <stdio.h>
////#include <string.h>
////
////int main()
////{
////	char str[1003] = { 0 };
////	gets(str);
////	char find;
////	scanf("%c", &find);
////	int count[128] = { 0 };
////	int len = strlen(str);
////	for (int i = 0; i < len; i++) {
////		count[str[i]] += 1; 
////	} int res = count[find];
////	if (find >= 'A' && find <= 'Z') 
////	{
////		res += count[find + 32];
////	}
////	else if (find >= 'a' && find <= 'z') 
////	{
////		
////		res += count[find - 32];
////	} 
////	printf("%d\n", res);
////	return 0;
////}
//
//
//
//
//
//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		this->test();
//	}
//	virtual void test()
//	{
//		cout << "A()" << endl;
//	}
//	void change()
//	{
//		test();
//	}
//	virtual ~A()
//	{
//		test();
//	}
//};
//
//class B : public A
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	virtual void test()
//	{
//		cout << "B()" << endl;
//	}
//	virtual ~B()
//	{
//		test();
//	}
//};
//
//int main()
//{
//	A* p = new B;
//	p->change();
//	//B b;
//	//b.change();
//	delete p;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

////class Solution {
////public:
////    int maxArea(vector<int>& height)
////    {
////        int i = 0;
////        int j = height.size() - 1;
////        int area = 0;
////        int ret = 0;
////        while (i < j)
////        {
////            area = (j - i) * min(height[i], height[j]);
////            ret = max(ret, area);
////            if (height[i] < height[j])
////            {
////                i++;
////            }
////            else
////                j--;
////        }
////        return ret;
////    }
////};
//
//int main()
//{
//    Solution s;
//    vector<int> v = { 1,8,6,2,5,4,8,3,7 };
//    s.maxArea(v);
//    return 0;
//}


//class Solution {
//public:
//    int triangleNumber(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        int a = 0;
//        int b = nums.size() - 2;
//        int c = nums.size() - 1;
//        int count = 0;
//        while (c > 1)
//        {
//            while (a < b)
//            {
//                if (nums[a] + nums[b] > nums[c])
//                {
//                    count += b - a;
//                    b--;
//                }
//                else
//                {
//                    a++;
//                }
//            }
//            c--;
//            a = 0;
//            b = c - 1;
//        }
//        return count;
//    }
//};
//
//int main()
//{
//    vector<int> v = { 2,2,4,3 };
//    Solution s;
//    cout << s.triangleNumber(v);
//    return 0;
//}




//class Solution {
//public:
//    vector<int> twoSum(vector<int>& price, int target) 
//    {
//        int left = 0;
//        int right = price.size() - 1;
//        while (left < right)
//        {
//            if (price[left] + price[right] > target)
//            {
//                right--;
//            }
//            else if (price[left] + price[right] < target)
//            {
//                left++;
//            }
//            else
//            {
//                vector<int> v;
//                v.push_back(price[right]);
//                v.push_back(price[left]);
//                return v;
//            }
//        }
//    }
//};


////三数之和
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> v;
//        int a = 0;
//        int b = nums.size() - 2;
//        int c = nums.size() - 1;
//        while (c > 1)
//        {
//            if (c != nums.size() - 1 && nums[c] == nums[c + 1])
//            {
//                c--;
//                a = 0;
//                b = c - 1;
//                continue;
//            }
//              
//            while (a < b)
//            {
// 
//                if (nums[a] + nums[b] > -nums[c])
//                {
//                    b--;
//                }
//                else if (nums[a] + nums[b] < -nums[c])
//                {
//                    a++;
//                }
//                else
//                {
//                    vector<int> tmp = { nums[a], nums[b], nums[c] };
//                    if (!v.empty() && v[v.size() - 1] == tmp)
//                    {
//                        b--;
//                        continue;
//                    }
//                    v.push_back({ nums[a] , nums[b] , nums[c] });
//                    b--;
//                }
//            }
//            c--;
//            a = 0;
//            b = c - 1;
//        }
//        //if (v.size() < 2)
//        //    return v;
//        //sort(v.begin(), v.end());
//        //vector<vector<int>>::iterator it = v.begin();
//        //while (it + 1 != v.end())
//        //{
//        //    if (*it == *(it + 1))
//        //    {
//        //        it = v.erase(it);
//        //        continue;
//        //    }
//        //    it++;
//        //}
//        return v;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> v = { -2,0,0,2,2 };
//    s.threeSum(v);
//    return 0;
//}


//四数之和
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {

    }
};