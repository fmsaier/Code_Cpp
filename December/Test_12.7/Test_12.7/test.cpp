#include <iostream>
#include <vector>
using namespace std;

//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}



//int main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(100);
//	v.resize(20);
//	cout << v.size() << ":" << v.capacity() << endl;
//	v.reserve(50);
//	v.resize(5);
//	cout << v.size() << ":" << v.capacity() << endl;
//	return 0;
//}



//136. 只出现一次的数字
//
//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        vector<int>::iterator it = nums.begin();
//        int num = 0;
//        for (it; it != nums.end(); it++)
//        {
//            num ^= *it;
//        }
//        return num;
//    }
//};



//118. 杨辉三角
//
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vt;
//        vt.resize(numRows);
//        for (int i = 0; i < numRows; i++)
//        {
//            vt[i].resize(i + 1, 0);
//            vt[i].front() = vt[i].back() = 1;
//        }
//        for (int i = 0; i < numRows; i++)
//        {
//            for (int j = 0; j < vt[i].size(); j++)
//            {
//                if (vt[i][j] != vt[i].front() && vt[i][j] != vt[i].back())
//                {
//                    vt[i][j] = vt[i - 1][j - 1] + vt[i - 1][j];
//                }
//            }
//        }
//        return vt;
//    }
//};





//26. 删除有序数组中的重复项
//
//给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
//
//考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
//
//更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
//返回 k

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int cur = 1, prev = 0;
//        while (cur < nums.size())
//        {
//            if (nums[cur] == nums[prev])
//            {
//                cur++;
//            }
//            else
//            {
//                prev++;
//                nums[prev] = nums[cur];
//                cur++;
//            }
//        }
//        return prev + 1;
//    }
//};




//17. 电话号码的字母组合
//
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vt;
        vt.resize(8);
        for (int i = 0; i < 8; i++)
        {
            if (i == 5 || i == 7)
            {
                vt[i].resize(4);
            }
            else
                vt[i].resize(3);
        }   
        int i = 0, j = 0;
 		for (char ch = 'a'; ch <= 'z'; ch++)
		{
            vt[j].replace(i, 1, 1, ch);
            i++;
            if (i >= vt[j].size())
            {
                i = 0;
                j++;
            }
		}
        vector<string> ret;
        //ret.resize()
        return vt;
    }
};
int main()
{
    Solution s;
    s.letterCombinations("123");
    return 0;
}