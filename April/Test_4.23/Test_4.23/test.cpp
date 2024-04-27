////#define _CRT_SECURE_NO_WARNINGS 1
////////
////////#include <iostream>
////////#include <assert.h>
////////
////////using namespace std;
////////
//////////using namespace std;
//////////
//////////namespace bit
//////////{
//////////	class string
//////////	{
//////////	public:
//////////		typedef char* iterator;
//////////		iterator begin()
//////////		{
//////////			return _str;
//////////		}
//////////
//////////		iterator end()
//////////		{
//////////			return _str + _size;
//////////		}
//////////
//////////		string(const char* str = "")
//////////			:_size(strlen(str))
//////////			, _capacity(_size)
//////////		{
//////////			cout << "string(char* str)" << endl;
//////////
//////////			_str = new char[_capacity + 1];
//////////			strcpy(_str, str);
//////////		}
//////////
//////////		// s1.swap(s2)
//////////		void swap(string& s)
//////////		{
//////////			::swap(_str, s._str);
//////////			::swap(_size, s._size);
//////////			::swap(_capacity, s._capacity);
//////////		}
//////////
//////////		// 拷贝构造 -- 左值
//////////		string(const string& s)
//////////			:_str(nullptr)
//////////		{
//////////			cout << "string(const string& s) -- 深拷贝" << endl;
//////////
//////////			_str = new char[s._capacity + 1];
//////////			strcpy(_str, s._str);
//////////			_size = s._size;
//////////			_capacity = s._capacity;
//////////		}
//////////
//////////		// 移动构造 -- 右值(将亡值)
//////////		string(string&& s)
//////////		{
//////////			cout << "string(string&& s) -- 移动拷贝" << endl;
//////////			swap(s);
//////////		}
//////////
//////////		// 拷贝赋值
//////////		// s2 = tmp
//////////		string& operator=(const string& s)
//////////		{
//////////			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
//////////			string tmp(s);
//////////			swap(tmp);
//////////
//////////			return *this;
//////////		}
//////////
//////////		// 移动赋值
//////////		string& operator=(string&& s)
//////////		{
//////////			cout << "string& operator=(string&& s) -- 移动拷贝" << endl;
//////////			swap(s);
//////////
//////////			return *this;
//////////		}
//////////
//////////		~string()
//////////		{
//////////			delete[] _str;
//////////			_str = nullptr;
//////////		}
//////////
//////////		char& operator[](size_t pos)
//////////		{
//////////			assert(pos < _size);
//////////			return _str[pos];
//////////		}
//////////
//////////		void reserve(size_t n)
//////////		{
//////////			if (n > _capacity)
//////////			{
//////////				char* tmp = new char[n + 1];
//////////				strcpy(tmp, _str);
//////////				delete[] _str;
//////////				_str = tmp;
//////////
//////////				_capacity = n;
//////////			}
//////////		}
//////////
//////////		void push_back(char ch)
//////////		{
//////////			if (_size >= _capacity)
//////////			{
//////////				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//////////				reserve(newcapacity);
//////////			}
//////////
//////////			_str[_size] = ch;
//////////			++_size;
//////////			_str[_size] = '\0';
//////////		}
//////////
//////////		//string operator+=(char ch)
//////////		string& operator+=(char ch)
//////////		{
//////////			push_back(ch);
//////////			return *this;
//////////		}
//////////
//////////		const char* c_str() const
//////////		{
//////////			return _str;
//////////		}
//////////	private:
//////////		char* _str = nullptr;
//////////		size_t _size = 0;
//////////		size_t _capacity = 0; // 不包含最后做标识的\0
//////////	};
//////////
//////////	bit::string* to_string(int value)
//////////	{
//////////		bool flag = true;
//////////		if (value < 0)
//////////		{
//////////			flag = false;
//////////			value = 0 - value;
//////////		}
//////////
//////////		bit::string str;
//////////		while (value > 0)
//////////		{
//////////			int x = value % 10;
//////////			value /= 10;
//////////			str += ('0' + x);
//////////		}
//////////		if (flag == false)
//////////		{
//////////			str += '-';
//////////		}
//////////
//////////		std::reverse(str.begin(), str.end());
//////////		return &str;
//////////	}
//////////}
////////////template <class T>
//////////class A
//////////{
//////////public:
//////////	A()
//////////	{
//////////		_a = new int(1);
//////////	}
//////////	/*~A()
//////////	{
//////////		cout << "~A()" << endl;
//////////	}*/
//////////	int* _a;
//////////};
//////////
////////////template <class T>
//////////A* Test()
//////////{
//////////	A* ret = &A();
//////////	return ret;
//////////}
////////
//////////int* Test1()
//////////{
//////////	int x = 10;
//////////	return &x;
//////////}
//////////void Test2()
//////////{
//////////	int y = 20;
//////////}
//////////
//////////int main()
//////////{
//////////	int* p = Test1();
//////////	cout << *p << endl;
//////////	Test2();
//////////	cout << *p << endl;
//////////}
////////
////////struct ListNode {
////////	int val;
////////	ListNode* next;
////////	ListNode() : val(0), next(nullptr) {}
////////	ListNode(int x) : val(x), next(nullptr) {}
////////	ListNode(int x, ListNode* next) : val(x), next(next) {}
////////
////////};
////////
////////
////////class Solution {
////////public:
////////    ListNode* reverseList(ListNode* head)
////////    {
////////        if (!head || !head->next)
////////            return head;
////////        ListNode* ret = reverseList(head->next);
////////        ListNode* next = head->next;
////////        next->next = head;
////////        head->next = nullptr;
////////        return ret;
////////    }
////////    void reorderList(ListNode* head)
////////    {
////////        ListNode* fast = head;
////////        ListNode* slow = head;
////////        while (fast->next && fast->next->next)
////////        {
////////            fast = fast->next->next;
////////            slow = slow->next;
////////        }
////////        //ListNode* tmp = slow;
////////        if (fast->next)
////////        {
////////            slow = slow->next;
////////        }
////////        //tmp->next = nullptr;
////////        slow = reverseList(slow);
////////        ListNode* cur = head;
////////        ListNode* next = cur->next;
////////        fast = slow->next;
////////        while(cur)
////////        {
////////            cur->next = slow;
////////            slow->next = next;
////////            slow = fast;
////////            fast = fast->next;
////////            if (!fast)
////////                break;
////////            cur = next;
////////            next = next->next;
////////        }
////////    }
////////};
////////
////////int main()
////////{
////////    ListNode* node1 = new ListNode(1);
////////    ListNode* node2 = new ListNode(2);
////////    ListNode* node3 = new ListNode(3);
////////    ListNode* node4 = new ListNode(4);
////////    ListNode* node5 = new ListNode(5);
////////
////////    node1->next = node2;
////////    node2->next = node3;
////////    node3->next = node4;
////////    node4->next = node5;
////////
////////    Solution s;
////////    s.reorderList(node1);
////////}
//////
//////
//////
////////#include <iostream>
////////#include <vector>
////////
////////using namespace std;
////////
////////class Solution {
////////public:
////////    vector<vector<int>> ret;
////////    bool check[7];
////////    vector<int> v;
////////    void _permute(vector<int>& nums)
////////    {
////////        if (v.size() == nums.size())
////////        {
////////            ret.push_back(v);
////////            return;
////////        }
////////        for (int i = 0; i < nums.size(); i++)
////////        {
////////            if (!check[i])
////////            {
////////                v.push_back(nums[i]);
////////                check[i] = true;
////////                _permute(nums);
////////                //恢复现场
////////                check[i] = false;
////////                v.pop_back();
////////            }
////////        }
////////    }
////////    vector<vector<int>> permute(vector<int>& nums)
////////    {
////////        _permute(nums);
////////        return ret;
////////    }
////////};
////////int main()
////////{
////////    Solution s;
////////    vector<int> v = { 1,2,3 };
////////    s.permute(v);
////////    return 0;
////////}
//////
//////#include <iostream>
//////#include <vector>
//////
//////using namespace std;
//////
//////
////////class Solution {
////////public:
////////    vector<vector<int>> ret;
////////    vector<int> v;
////////
////////    void _subsets(vector<int>& nums, int i)
////////    {
////////        if (i == nums.size())
////////        {
////////            ret.push_back(v);
////////            return;
////////        }
////////        //选
////////        _subsets(nums, i + 1);
////////        v.push_back(nums[i]);
////////        //不选  
////////        _subsets(nums, i + 1);
////////        v.pop_back();
////////    }
////////    vector<vector<int>> subsets(vector<int>& nums)
////////    {
////////        _subsets(nums, 0);
////////        return ret;
////////    }
////////};
////////
////////class Solution {
////////public:
////////    vector<vector<int>> ret;
////////    vector<int> v;
////////
////////    void _subsets(vector<int>& nums, int i)
////////    {
////////        if (i == nums.size())
////////            return;
////////        for (i; i < nums.size(); i++)
////////        {
////////            v.push_back(nums[i]);
////////            ret.push_back(v);
////////            _subsets(nums, i + 1);
////////            v.pop_back();
////////        }
////////    }
////////    vector<vector<int>> subsets(vector<int>& nums)
////////    {
////////        ret.push_back({});
////////        _subsets(nums, 0);
////////        return ret;
////////    }
////////};
//////
////////class Solution {
////////    int sum = 0;
////////public:
////////    void subset(vector<int>& nums, int i, int k)
////////    {
////////        if (i == nums.size())
////////            return;
////////
////////        for (i; i < nums.size(); i++)
////////        {
////////            int tmp = k;
////////            k ^= nums[i];
////////            sum += k;
////////            subset(nums, i + 1, k);
////////            k = tmp;
////////        }
////////    }
////////    int subsetXORSum(vector<int>& nums)
////////    {
////////        subset(nums, 0, 0);
////////        return sum;
////////    }
////////};
//////
//////
//////
//////class Solution
//////{
//////    vector<int> tmp;
//////public:
//////    vector<int> sortArray(vector<int>& nums)
//////    {
//////        tmp.resize(nums.size());
//////        mergeSort(nums, 0, nums.size() - 1);
//////        return nums;
//////    }
//////    //归并
//////    void mergeSort(vector<int>& nums, int left, int right)
//////    {
//////        if (left >= right)
//////            return;
//////        int mid = left + (right - left) / 2;
//////        mergeSort(nums, left, mid);
//////        mergeSort(nums, mid + 1, right);
//////        int cur1 = left, cur2 = mid + 1, i = 0;
//////        while (cur1 <= mid && cur2 <= right)
//////            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
//////        while (cur1 <= mid)
//////            tmp[i++] = nums[cur1++];
//////        while (cur2 <= right)
//////            tmp[i++] = nums[cur2++];
//////        for (i = left; i <= right; i++)
//////            nums[i] = tmp[i - left];
//////    }
//////    // 快排
//////    void qsort(vector<int>& nums, int l, int r)
//////    {
//////        if (l >= r) return;
//////        int left = l - 1, right = r + 1;
//////        int key = nums[l + rand() % (r - l + 1)];
//////        int i = l;
//////        while (i < right)
//////        {
//////            if (nums[i] == key)
//////                i++;
//////            else if (nums[i] < key)
//////                swap(nums[i++], nums[++left]);
//////            else 
//////                swap(nums[i], nums[--right]);
//////        }
//////        qsort(nums, l, left);
//////        qsort(nums, right, r);
//////    }
//////};
//////#include <iostream>
//////#include <cstdlib>
//////#include <ctime>
//////
//////using namespace std;
//////
//////int cnt = 0;
//////
//////// 随机打乱数组
//////void shuffle(int arr[], int n)
//////{
//////    cnt++;
//////    for (int i = 0; i < n; i++)
//////    {
//////        // 生成随机索引
//////        int j = rand() % n;
//////
//////        // 交换 arr[i] 和 arr[j]
//////        swap(arr[i], arr[j]);
//////    }
//////}
//////
//////// 判断是否已排序完毕
//////bool is_sorted(int arr[], int n)
//////{
//////    for (int i = 1; i < n; i++)
//////    {
//////        if (arr[i] < arr[i - 1])
//////        {
//////            return false;
//////        }
//////    }
//////
//////    return true;
//////}
//////
//////// Bogo Sort 算法
//////void bogo_sort(int arr[], int n)
//////{
//////    // 随机打乱，直到排列正确
//////    while (!is_sorted(arr, n))
//////    {
//////        shuffle(arr, n);
//////    }
//////}
//////
//////
//////int main()
//////{
//////    //Solution s;
//////    //vector<int> v = { 5,2,3,1 };
//////    //s.sortArray(v);
//////
//////    int arr[] = { 15,1,4749,78,3,18,4,51,87,41,5 };
//////    bogo_sort(arr, sizeof(arr) / 4);
//////    for (auto i : arr)
//////    {
//////        cout << i << " ";
//////    }
//////    cout << endl;
//////    cout << cnt << endl;
//////    return 0;
//////}
////
////
////#include <iostream>
////#include <thread>
////#include <mutex>
////#include <Windows.h>
////
////using namespace std;
////
////mutex m1, m2;
////
////void Test1()
////{	
////	m1.lock();
////	Sleep(1);
////	m2.lock();
////	m1.unlock();
////	m2.unlock();
////}
////void Test2()
////{
////	m2.lock();
////	Sleep(1);
////	m1.lock();
////	m1.unlock();
////	m2.unlock();
////}
////
////#include "test.h"
////
////template <>
////void Test(int x)
////{
////	cout << x << endl;
////}
////
////struct A
////{
////	static int b;
////	int a;
////	char c;
////	virtual void Test()
////	{
////
////	}
////};
////
////int main()
////{
////	Test(1);
////	cout << sizeof(A) << endl;;
////
////	return 0;
////}
//
//
//
//
//
//
//
//
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n, m, a, b;
//    cin >> n >> m >> a >> b;
//    int cnt = 0;
//    if (a > b)
//    {
//        if (m * 2 > n)
//        {
//            int tmp = n / 2;
//            cnt += tmp * a;
//            n -= tmp * 2;
//            m -= tmp;
//        }
//        else
//        {
//            int tmp = m;
//            cnt += tmp * a;
//            n -= tmp * 2;
//            m -= tmp;
//        }
//        while (n > 0 || m > 0)
//        {
//            if (n * 2 > m)
//            {
//                int tmp = m / 2;
//                cnt += tmp * b;
//                m -= tmp * 2;
//                n -= tmp;
//            }
//            else
//            {
//                int tmp = n;
//                cnt += tmp * b;
//                m -= tmp * 2;
//                n -= tmp;
//            }
//        }
//    }
//    else
//    {
//        if (n * 2 > m)
//        {
//            int tmp = m / 2;
//            cnt += tmp * b;
//            m -= tmp * 2;
//            n -= tmp;
//        }
//        else
//        {
//            int tmp = n;
//            cnt += tmp * b;
//            m -= tmp * 2;
//            n -= tmp;
//        }
//        while (n > 0 || m > 0)
//        {
//            if (m * 2 > n)
//            {
//                int tmp = n / 2;
//                cnt += tmp * a;
//                n -= tmp * 2;
//                m -= tmp;
//            }
//            else
//            {
//                int tmp = m;
//                cnt += tmp * a;
//                n -= tmp * 2;
//                m -= tmp;
//            }
//        }
//    }
//    cout << cnt << endl;
//}
//// 64 位输出请用 printf("%lld")



