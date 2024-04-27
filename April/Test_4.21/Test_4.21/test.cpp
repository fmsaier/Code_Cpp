//#include <iostream>
//
//using namespace std;
//
//
//struct ListNode 
//{
//	int val;
//	struct ListNode* next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//	/**
//	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	 *
//	 *
//     * @param head1 ListNode类
//     * @param head2 ListNode类
//     * @return ListNode类
//     */
//    ListNode* reverseList(ListNode* head, size_t& lsize)
//    {
//        if (head->next == nullptr)
//            return head;
//        ListNode* cur = head->next;
//        ListNode* pre = head;
//        ListNode* next = cur->next;
//        pre->next = nullptr;
//        while (cur->next)
//        {
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//            next = next->next;
//            lsize++;
//        }
//        cur->next = pre;
//        lsize += 2;
//        return cur;
//    }
//
//    ListNode* addInList(ListNode* head1, ListNode* head2)
//    {
//        size_t i = 0, j = 0;
//        int sum = 0;
//
//        head1 = reverseList(head1, i);
//        head2 = reverseList(head2, j);
//        ListNode* cur1 = head1, * cur2 = head2;
//        ListNode* ret = nullptr;
//        ListNode* cur3 = ret;
//        while (i > 0 && j > 0)
//        {
//            int tmp = cur1->val + cur2->val + sum;
//            i--;
//            j--;
//            cur1 = cur1->next;
//            cur2 = cur2->next;
//            sum = tmp / 10;
//            tmp = tmp % 10;
//            ListNode* newNode = new ListNode(tmp);
//            if (cur3 == nullptr)
//            {
//                cur3 = newNode;
//                ret = cur3;
//            }
//            else
//            {
//                cur3->next = newNode;
//                cur3 = cur3->next;
//            }
//
//        }
//        if (i <= 0) 
//        {
//            while (j > 0)
//            {
//                int tmp = cur2->val + sum;
//                j--;
//                cur2 = cur2->next;
//                sum = tmp / 10;
//                tmp = tmp % 10;
//                ListNode* newNode = new ListNode(tmp);
//                if (cur3 == nullptr)
//                    cur3 = newNode;
//                else
//                {
//                    cur3->next = newNode;
//                    cur3 = cur3->next;
//                }
//            }
//        }
//        else if (j <= 0)
//        {
//            while (i > 0)
//            {
//                int tmp = cur1->val + sum;
//                i--;
//                cur1 = cur1->next;
//                sum = tmp / 10;
//                tmp = tmp % 10;
//                ListNode* newNode = new ListNode(tmp);
//                if (cur3 == nullptr)
//                    cur3 = newNode;
//                else
//                {
//                    cur3->next = newNode;
//                    cur3 = cur3->next;
//                }
//            }
//        }
//        if (sum != 0)
//        {
//            ListNode* newNode = new ListNode(sum);
//            cur3->next = newNode;
//            cur3->next->next = nullptr;
//        }
//        else
//        {
//            cur3->next = nullptr;
//        }
//        size_t t = 0;
//        ret = reverseList(ret, t);
//        return ret;
//    }
//};
//
//
//int main()
//{
//    ListNode* head1 = new ListNode(9);
//    ListNode* node1 = new ListNode(3);
//    ListNode* node2 = new ListNode(7);
//
//    head1->next = node1;
//    node1->next = node2;
//
//    ListNode* head2 = new ListNode(6);
//    ListNode* node3 = new ListNode(3);
//    head2->next = node3;
//
//    Solution s;
//    s.addInList(head1, head2);
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
//    {
//        int ret = 0;
//        for (size_t i = 0; i < timeSeries.size(); i++)
//        {
//            if (i < timeSeries.size() - 1)
//            {
//                if (timeSeries[i + 1] - timeSeries[i] >= duration)
//                {
//                    ret += duration;
//                }
//                else
//                {
//                    ret += timeSeries[i + 1] - timeSeries[i];
//                }
//            }
//            else
//            {
//                ret += duration;
//            }
//            
//        }
//        return ret;
//    }
//};



//class Solution {
//public:
//    string convert(string s, int numRows)
//    {
//        int n = s.size();
//        int j = 0;
//        int tmp = 0;
//        while (tmp < n)
//        {
//            if (j % 2 == 0)
//                tmp += numRows;
//			else
//				tmp += numRows - 2 > 0 ? numRows - 2 : 0;
//			j++;
//		}
//		int k = 0;
//		bool isReverse = false;
//		vector<string> vstr(numRows, string(j, '\0'));
//		for (size_t i = 0; i < vstr[0].size(); i++)
//		{
//			if (i % 2 == 1)
//            {
//                vstr[0][i] = -1;
//                vstr[numRows - 1][i] = -1;
//            }
//
//        }
//        for (size_t i = 0; i < vstr[0].size(); i++)
//        {
//            if (!isReverse)
//            {
//                for (size_t j = 0; j < numRows; j++)
//                {
//                    if (k >= n)
//                        break;
//                    if (vstr[j][i] != -1)
//                    {
//                        vstr[j][i] = s[k++];
//                    }
//                }
//                isReverse = !isReverse;
//            }
//            else
//            {
//                for (size_t j = numRows - 1; j > 0; j--)
//                {
//                    if (k >= n)
//                        break;
//                    if (vstr[j][i] != -1)
//                    {
//                        vstr[j][i] = s[k++];
//                    }
//                }
//                isReverse = !isReverse;
//            }
//            if (k >= n)
//                break;
//        }
//        string ret;
//        k = 0;
//        for (size_t i = 0; i < numRows; i++)
//        {
//            for (size_t j = 0; j < vstr[0].size(); j++)
//            {
//                if (vstr[i][j] != -1 && vstr[i][j] != '\0')
//                {
//                    ret += vstr[i][j];
//                    k++;
//                }
//                if (k >= n)
//                    break;
//            }
//            if (k >= n)
//                break;
//        }
//        return ret;
//
//    }
//};
//
//int main()
//{
//    Solution s;
//    string str = "AB";
//    cout << s.convert(str, 1);
//    return 0;
//}

#include <unordered_map>

//class Solution {
//public:
//    string sayGet(string& str)
//    {
//        string ret;
//        int cnt = 0;
//        int right = 0;
//        int left = 0;
//        while (right < str.size())
//        {
//            if (right == str.size() - 1 || str[right] != str[right + 1])
//            {
//                cnt = right - left + 1;
//                left = right + 1;
//                ret += cnt + '0';
//                ret += str[right];
//            }
//            right++;
//        }
//        return ret;
//    }
//    string countAndSay(int n) 
//    {
//        vector<string> vstr(n, "1");
//        for (size_t i = 1; i < vstr.size(); i++)
//        {
//            vstr[i] = sayGet(vstr[i - 1]);
//        }
//        return vstr[n - 1];
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.countAndSay(4);
//    return 0;
//}



class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        unordered_map<char, int> hash;
        int cnt = 0;
        int maxCnt = 0;
        for (size_t i = 0; i < croakOfFrogs.size(); i++)
        {
            //croak
            if (croakOfFrogs[i] == 'r' && hash['c'] <= hash['r'])
                return -1;           
            if (croakOfFrogs[i] == 'o' && hash['r'] <= hash['o'])
                return -1;
            if (croakOfFrogs[i] == 'a' && hash['o'] <= hash['a'])
                return -1;
            if (croakOfFrogs[i] == 'k' && hash['a'] <= hash['k'])
                return -1;
            hash[croakOfFrogs[i]]++;
        }
        int tmp = hash['c'];
        for (auto& elem : hash)
        {
            if (elem.second != tmp)
                return -1;
        }
        for (size_t i = 0; i < croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i] == 'c')
            {
                cnt++;
                maxCnt = max(cnt, maxCnt);
            }
            if (croakOfFrogs[i] == 'k')
                cnt--;
        }
        return maxCnt;
    }
};

int main()
{
    Solution s;
    cout << s.minNumberOfFrogs("croakcroak");
    return 0;
}