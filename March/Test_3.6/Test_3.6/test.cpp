//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//    string s;
//    getline(cin, s);
//    reverse(s.begin(), s.end());
//    cout << s;
//    return 0;
//}
//// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
//int GetMax(const string& s1, const string& s2)
//{
//    int len1 = s1.size();
//    int len2 = s2.size();
//
//    vector<vector<int>> msc(len1, vector<int>(len2, 0));
//
//    int max = 0;
//    for (int i = 0; i < len1; i++)
//    {
//        for (int j = 0; j < len2; ++j)
//        {
//            if (s2[j] == s1[i])
//            {
//                if (i >= 1 && j >= 1)
//                    msc[i][j] = msc[i - 1][j - 1] + 1;
//                else
//                    msc[i][j] = 1;
//
//                if (msc[i][j] > max)
//                    max = msc[i][j];
//            }
//        }
//    }
//    return max;
//}
//
//int main()
//{
//    string s1, s2;
//    while (cin >> s1 >> s2) {
//        int max = GetMax(s1, s2);
//        cout << max << endl;
//    }
//    return 0;
//}



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
//                if (nums[c] < 0)
//                    break;
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
//        return v;
//    }
//};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> v;
        //防止数据少于四个
        if (nums.size() < 4)
            return v;
        sort(nums.begin(), nums.end());
        int a = nums.size() - 1;
        int b = 2;
        int c = 1;
        int d = 0;
        int length = nums.size();
        long long sum = 0;
        while (d < nums.size() - 3)
        {
            if (nums[d] > target && target >= 0)
                break;
            while (c < nums.size() - 2)
            {
                while (b < a)
                {
                    sum = (long)nums[d] + nums[c] + nums[b] + nums[a];
                    if (sum < target)
                    {
                        b++;
                        //if (b >= a)
                        //    continue;
                        ////如果下一个b跟上一个b一样就是重复
                        //if (nums[b] == nums[b - 1])
                        //    b++;
                    }
                    else if (sum > target)
                    {
                        a--;
                        //if (b >= a)
                        //    continue;
                        ////如果下一个a跟上一个a一样就是重复
                        //if (nums[a] == nums[a + 1])
                        //    a--;
                    }
                    else
                    {
                        //if (b >= a)
                        //    continue;
                        //vector<int> tmp = { nums[a], nums[b], nums[c],nums[d] };
                        ////防止a--之后还是可以直接push，也防止刚开始就是空的第一个没重复的进不来
                        //if (!v.empty() && tmp == v[v.size() - 1])
                        //{
                        //    a--;
                        //    continue;
                        //}
                        //v.push_back({ nums[a], nums[b], nums[c],nums[d] });
                        //a--;
                        v.push_back({ nums[a], nums[b], nums[c],nums[d] });
                        //两个都改正常没重复就不会有问题
                        a--;
                        b++;
                        //c跟d一直循环就不会有外部的问题
                        //只要一直循环到b不一样就行
                        while (nums[b] == nums[b - 1])
                        {
                            b++;
                            if (b >= a || b >= nums.size() - 1)
                                break;
                        }
                    }
                }

                c++;
                b = c + 1;
                a = nums.size() - 1;
                if (c >= nums.size() - 2)
                    continue;
                //c只要重复那本质后面的就是上一次的子集就循环到c不一样的
                while (nums[c] == nums[c - 1])
                {
                    c++;
                    b = c + 1;
                    a = nums.size() - 1;
                    if (c >= nums.size() - 2)
                        break;
                }
            }
            d++;
            c = d + 1;
            b = c + 1;
            a = nums.size() - 1;
            if (d >= nums.size() - 3)
                continue;
            //d只要重复那本质后面的就是上一次的子集就循环到d不一样的
            while (nums[d] == nums[d - 1])
            {
                d++;
                c = d + 1;
                b = c + 1;
                a = nums.size() - 1;
                if (d >= nums.size() - 3)
                    break;
            }
        }
        return v;
    }

};
int main()
{
    Solution s;
    vector<int> v = { 7,-8,-7,2,-7,-7,10,-6,10,-9,2,-7,-4,-7 };
    vector<vector<int>> vv = s.fourSum(v, -22);
    return 0;
}