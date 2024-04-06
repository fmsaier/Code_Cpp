#define _CRT_SECURE_NO_WARNINGS

//要求：
//
//2.1使用代码打开当前路径下的“bite”文件（如果文件不存在在创建文件），
// 向文件当中写入“linux so easy!”.
//
//2.2 在从文件当中读出文件当中的内容， 打印到标准输出当中； 关闭文件流指针

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <time.h>
using namespace std;

//int main()
//{
//	FILE* fp = fopen("bite.txt", "w");
//	if (fp == NULL)
//		return  1;
//	char str[] = "linux so easy!\n";
//	fprintf(fp, "%s", str);
//	fclose(fp);
//	fp = fopen("bite.txt", "r");
//	if (fp == NULL)
//		return  1;
//	char tmp[50];
//	int a = 0;
//	fscanf(fp, "%[^\n]s", tmp);
//	fprintf(stdout, "%s", tmp);
//	//scanf("%[^#]d", &a);
//	//cout << a << endl;
//	fclose(fp);
//	return 0;
//}
//

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() 
        : val(0), 
        left(nullptr), 
        right(nullptr) 
    {}
    TreeNode(int x) 
        : val(x),
        left(nullptr),
        right(nullptr) 
    {}
    TreeNode(int x, TreeNode* left, TreeNode* right) 
        : val(x), 
        left(left),
        right(right) 
    {}
};

//class Solution {
//public:
//    void _tree2str(TreeNode* root,string & ret)
//    {
//        if (root == nullptr)
//            return;
//        ret += to_string(root->val);
//        if (root->left || root->right)
//        {
//            ret += '(';
//            _tree2str(root->left, ret);
//            ret += ')';
//            if (root->right)
//            {
//                ret += '(';
//                _tree2str(root->right, ret);
//                ret += ')';
//            }
//        }
//
//    }
//    string tree2str(TreeNode* root) 
//    {
//        string ret;
//        _tree2str(root, ret);
//        return ret;
//    }
//};



//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) 
//    {
//        vector<vector<int>> vv;
//        int n = 1;
//        if (root == nullptr)
//            return vv;
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty())
//        {
//            vector<int> v;
//            n = q.size();
//            while (n--)
//            {
//                if(q.front()->left)
//                    q.push(q.front()->left);
//                if (q.front()->right)
//                    q.push(q.front()->right);
//                v.push_back(q.front()->val);
//                q.pop();
//            }
//            vv.push_back(v);
//        }
//        return vv;
//    }
//};
//
//int main()
//{
//
//    return 0;
//}



//class Solution {
//public:
//    bool FindNode(TreeNode* root, TreeNode* target)
//    {
//        if (root == nullptr)
//            return false;
//        if (root == target)
//            return true;
//        return FindNode(root->left, target) ||
//            FindNode(root->right, target);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        TreeNode* cur = root;
//        bool pInLeft, pInRight, qInLeft, qInRight;
//        while (cur)
//        {
//            if (cur == p || cur == q)
//                return cur;
//            pInLeft = FindNode(cur->left, p);
//            pInRight = FindNode(cur->right, p);
//            qInLeft = FindNode(cur->left, q);
//            qInRight = FindNode(cur->right, q);
//            if (qInLeft && pInLeft)
//                cur = cur->left;
//            else if (qInRight && pInRight)
//                cur = cur->right;
//            else
//                return cur;
//            //if(FindNode(cur->left,))
//
//        }
//        return nullptr;
//    }
//};

//class Solution {
//public:
//    bool GetPath(TreeNode* root, TreeNode* target, stack<TreeNode*>& path)
//    {
//        if (root == nullptr)
//            return false;
//        path.push(root);
//        if (root == target)
//            return true;
//        if (GetPath(root->left, target, path))
//            return true;
//        if (GetPath(root->right, target, path))
//            return true;
//        path.pop();
//        return false;
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        stack<TreeNode*> pathP;
//        stack<TreeNode*> pathQ;
//        GetPath(root, p, pathP);
//        GetPath(root, q, pathQ);
//        int i = pathP.size() - pathQ.size();
//        if (i < 0)
//        {
//            i = -i;
//            while (i--)
//            {
//                pathQ.pop();
//            }
//            while (!pathP.empty())
//            {
//                if (pathP.top() == pathQ.top())
//                    return pathP.top();
//                pathQ.pop();
//                pathP.pop();
//            }
//        }
//        while (i--)
//        {
//            pathP.pop();
//        }
//        while (!pathP.empty())
//        {
//            if (pathP.top() == pathQ.top())
//                return pathP.top();
//            pathQ.pop();
//            pathP.pop();
//        }
//        return nullptr;
//    }
//};



//class Solution {
//public:
//    void _Convert(TreeNode* root, TreeNode*& pre)
//    {
//        if (root == nullptr)
//            return;
//        _Convert(root->left, pre);
//
//        root->left = pre;
//        if (pre)
//            pre->right = root;
//        pre = root;
//
//
//        _Convert(root->right, pre);
//    }
//    TreeNode* Convert(TreeNode* pRootOfTree)
//    {
//        if (pRootOfTree == nullptr)
//            return nullptr;
//        TreeNode* pre = nullptr;
//        _Convert(pRootOfTree, pre);
//        TreeNode* head = pRootOfTree;
//        TreeNode* tail = pRootOfTree;
//        while (head->left)
//        {
//            head = head->left;
//        }
//        return head;
//    }
//};


//class Solution {
//public:
//    //pre [3, 9, 20, 15, 7]
//    //in  [9, 3, 15, 20, 7]
//    void _buildTree(vector<int>& preorder, vector<int>& inorder, TreeNode*& pre, int left, int right, int& index)
//    {
//        if (left > right)
//            return;
//        int i = 0;
//        index++;
//        for (i = left; i <= right; i++)
//        {
//            if (inorder[i] == preorder[index])
//                break;
//        }
//        TreeNode* cur = new TreeNode(inorder[i]);
//     
//        pre = cur;
//        //左
//        _buildTree(preorder, inorder, cur->left, left, i - 1, index);
//        //右
//        _buildTree(preorder, inorder, cur->right, i + 1, right, index);
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
//    {
//        TreeNode* pre = nullptr;
//        int i = -1;
//        _buildTree(preorder, inorder, pre, 0, preorder.size() - 1, i);
//        return pre;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<int> preorder = { 3, 9, 20, 15, 7 };
//    vector<int> inorder = { 9, 3, 15, 20, 7 };
//    s.buildTree(preorder, inorder);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//
//int days[2000];
//bool sports[100];
//short n, m, l, r;
//int q;
//
//int main(void) 
//{
//    //memset(days, 0, sizeof(days));
//    scanf("%hd%hd", &n, &m);
//    for (q = 0; q < n; q++) scanf("%d", days + q);
//    for (q = 0; q < n; q++) days[q]--;
//    scanf("%d", &q);
//    while (q--) {
//        memset(sports, 0, sizeof(sports));
//        scanf("%hd%hd", &l, &r);
//        n = 0;
//        for (l--, r--; l <= r; l++) sports[days[l]] ? 0 : ((sports[days[l]] = true), n++);
//        printf("%d\n", n);
//    }
//    return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<time.h>
//using namespace std;
//int N = 5, M = 3, Q=3, l=1, r=4;
//int day[2001] = {1,2,3,2,2};
//int sports[101];
//int main()
//{
//    //cin >> N >> M;
//    /*for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", day + i);
//    }*/
//
//   //cin >> Q;
//    clock_t begin1 = clock();
//    while (Q--)
//    {
//        memset(sports, 0, sizeof(sports));
//        //cin >> l >> r;
//        int ans = 0;
//        for (; l <= r; l++) 
//            
//            sports[day[l]] ? 0 : ((sports[day[l]] = 1), ans++);
//        printf("%d\n", ans);
//    }
//    clock_t end1 = clock();
//    cout << end1 - begin1;
//    return 0;
//}



//class Solution {
//public:
//    //pre [3, 9, 20, 15, 7]
//    //in  [9, 3, 15, 20, 7]
//    void _buildTree(vector<int>& postorder, vector<int>& inorder, TreeNode*& pre, int left, int right, int& index)
//    {
//        if (left > right)
//            return;
//        int i = 0;
//        index--;
//        for (i = right; i >= left; i--)
//        {
//            if (inorder[i] == postorder[index])
//                break;
//        }
//        TreeNode* cur = new TreeNode(inorder[i]);
//     
//        pre = cur;
//        //右
//        _buildTree(postorder, inorder, cur->right, i + 1, right, index);
//        //左
//        _buildTree(postorder, inorder, cur->left, left, i - 1, index);
//       
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//    {
//        TreeNode* pre = nullptr;
//        int i = postorder.size();
//        _buildTree(postorder, inorder, pre, 0, postorder.size() - 1, i);
//        return pre;
//    }
//};


//
//class Solution {
//public:
//    void _preorderTraversal(TreeNode* root, vector<int>& ret) 
//    {
//        if (!root)
//            return;
//        ret.push_back(root->val);
//        _preorderTraversal(root->left, ret);
//        _preorderTraversal(root->right, ret);
//    }
//    vector<int> preorderTraversal(TreeNode* root) 
//    {
//        vector<int> ret;
//        _preorderTraversal(root, ret);
//        return ret;
//    }
//};



//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        vector<int> ret;
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        //s.push(root);
//        while (cur || !s.empty())
//        {
//            while (cur)
//            {
//                s.push(cur);
//                ret.push_back(s.top()->val);
//                cur = cur->left;
//            }
//
//            if (s.top()->right)
//            {
//                cur = s.top()->right;
//            }
//            s.pop();
//        }
//        return ret;
//    }
//};




//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) 
//    {
//        vector<int> ret;
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        //s.push(root);
//        while (cur || !s.empty())
//        {
//            while (cur)
//            {
//                s.push(cur);
//
//                cur = cur->left;
//            }
//
//            if (s.top()->right)
//            {
//                cur = s.top()->right;
//            }
//            ret.push_back(s.top()->val);
//            s.pop();
//        }
//        return ret;
//    }
//};



//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        vector<int> ret;
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        TreeNode* pre = nullptr;
//        //s.push(root);
//        while (cur || !s.empty())
//        {
//            while (cur)
//            {
//                s.push(cur);
//                cur = cur->left;
//            }
//
//            if (s.top()->right)
//            {
//                //pre = s.top();
//                cur = s.top()->right;
//            }
//            if (!s.top()->right || pre == s.top()->right)
//            {
//                ret.push_back(s.top()->val);
//                pre = s.top();
//                s.pop();
//                //cur = s.top();
//            }
//
//        }
//        return ret;
//    }
//};
//



//class Solution {
//public:
//    //template <class T>
//    class Compare
//    {
//    public:
//		bool operator()(pair<string, int> p1, pair<string, int> p2)
//		{
//            if (p1.second > p2.second)
//                return true;
//            return false;
//		}
//	};
//    vector<string> topKFrequent(vector<string>& words, int k)
//    {
//        map<string, int> dic;
//        for (auto& str : words)
//        {
//            dic[str]++;
//        }
//        Compare com;
//        vector<pair<string, int>> v(dic.begin(), dic.end());
//        stable_sort(v.begin(), v.end(), com);
//        vector<string> ret;
//        for (int i = 0; i < k; i++)
//        {
//            ret.push_back(v[i].first);
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" }; 
//    s.topKFrequent(words, 2);
//    return 0;
//}
//
//class Compare
//{
//public:
//	bool operator()(pair<string, int> p1, pair<string, int> p2)
//	{
//		if (p1.second > p2.second)
//			return true;
//		return false;
//	}
//};
//vector<pair<string, int>> topKFrequent(vector<string>& words)
//{
//	map<string, int> dic;
//	for (auto& str : words)
//	{
//		dic[str]++;
//	}
//	Compare com;
//	vector<pair<string, int>> v(dic.begin(), dic.end());
//	stable_sort(v.begin(), v.end(), com);
//	
//	return v;
//}
//
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    string second;
//    getline(cin, second);
//    
//	vector<string> words;
//    int begin = 0;
//    for (int i = 0; i < second.size(); i++)
//    {
//        second[i] = tolower(second[i]);
//        if (second[i] == ' ' || second[i] == '.')
//        {
//            string tmp(second.begin()+begin, second.begin() + i);
//            words.push_back(tmp);
//            begin = i + 1;
//        }
//
//    }
//    vector<pair<string, int>> ret = topKFrequent(words);
//    for (auto& i : ret)
//    {
//        cout << i.first << ":" << i.second << endl;
//    }
//    return 0;
//}

//class A
//{
//    int a = 0;
//public:
//    virtual void Test() 
//    {
//
//    }
//};
//class B final : public A
//{
//    int b;
//
//public:
//    B()
//    {
//        //a.a = 1;
//        b = 0;
//    }
//    B(const B& b) = default;
//    virtual void Test() override final
//    {
//
//    }
//};

template <size_t N>
void Func()
{
    cout << N << endl;
    Func<N - 1>();
}

template<>
void Func<1>()
{
    cout << 1 << endl;
}
void _Test()
{

}
template <class T, class ...Args>
void _Test(T&& t, Args&& ...args)
{
	_Test(args...);
}
template <class ...Args>
void Test(Args&& ...args)
{
	_Test(args...);
}

int main()
{
    Test(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    Func<2000>();
    return 0;
}
