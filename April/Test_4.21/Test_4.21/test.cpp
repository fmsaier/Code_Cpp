#include <iostream>

using namespace std;


struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head, size_t& lsize)
    {
        if (head->next == nullptr)
            return head;
        ListNode* cur = head->next;
        ListNode* pre = head;
        ListNode* next = cur->next;
        pre->next = nullptr;
        while (cur->next)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
            lsize++;
        }
        cur->next = pre;
        lsize += 2;
        return cur;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        size_t i = 0, j = 0;
        int sum = 0;

        head1 = reverseList(head1, i);
        head2 = reverseList(head2, j);
        ListNode* cur1 = head1, * cur2 = head2;
        ListNode* ret = nullptr;
        ListNode* cur3 = ret;
        while (i > 0 && j > 0)
        {
            int tmp = cur1->val + cur2->val + sum;
            i--;
            j--;
            cur1 = cur1->next;
            cur2 = cur2->next;
            sum = tmp / 10;
            tmp = tmp % 10;
            ListNode* newNode = new ListNode(tmp);
            if (cur3 == nullptr)
            {
                cur3 = newNode;
                ret = cur3;
            }
            else
            {
                cur3->next = newNode;
                cur3 = cur3->next;
            }

        }
        if (i <= 0) 
        {
            while (j > 0)
            {
                int tmp = cur2->val + sum;
                j--;
                cur2 = cur2->next;
                sum = tmp / 10;
                tmp = tmp % 10;
                ListNode* newNode = new ListNode(tmp);
                if (cur3 == nullptr)
                    cur3 = newNode;
                else
                {
                    cur3->next = newNode;
                    cur3 = cur3->next;
                }
            }
        }
        else if (j <= 0)
        {
            while (i > 0)
            {
                int tmp = cur1->val + sum;
                i--;
                cur1 = cur1->next;
                sum = tmp / 10;
                tmp = tmp % 10;
                ListNode* newNode = new ListNode(tmp);
                if (cur3 == nullptr)
                    cur3 = newNode;
                else
                {
                    cur3->next = newNode;
                    cur3 = cur3->next;
                }
            }
        }
        if (sum != 0)
        {
            ListNode* newNode = new ListNode(sum);
            cur3->next = newNode;
            cur3->next->next = nullptr;
        }
        else
        {
            cur3->next = nullptr;
        }
        size_t t = 0;
        ret = reverseList(ret, t);
        return ret;
    }
};


int main()
{
    ListNode* head1 = new ListNode(9);
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(7);

    head1->next = node1;
    node1->next = node2;

    ListNode* head2 = new ListNode(6);
    ListNode* node3 = new ListNode(3);
    head2->next = node3;

    Solution s;
    s.addInList(head1, head2);
    return 0;
}