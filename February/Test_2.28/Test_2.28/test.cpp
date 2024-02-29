////#include <iostream>
////using namespace std;
////
////int main() 
////{
////	int year, month, day, time = 0;
////	cin >> year >> month >> day;
////	int monDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
////	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
////	{
////		monDay[2] = 29;
////	}
////	for (int i = 0; i < month; i++)
////	{
////		time += monDay[i];
////	}
////	time += day;
////
////
////	cout << time << endl;
////	return 0;
////}
////// 64 位输出请用 printf("%lld")
//
//
//
//
//
//
//#include <iostream>
//using namespace std;
//
//int lucky = 0;      
//struct result_list
//{
//    int result[100];
//    int num_of_result = 0;
//}result;        
//
//void sort(int num[], int n)        
//{
//    for (int i = 0; i < n - 1; i++)
//    {
//        int min = i, tmp;
//        for (int j = i + 1; j < n; j++)
//        {
//            if (num[j] < num[min])
//                min = j;
//        }
//        tmp = num[i];
//        num[i] = num[min];
//        num[min] = tmp;
//    }
//}
//
//void append(int n_append)       
//{
//    result.result[result.num_of_result] = n_append;
//    result.num_of_result++;
//}
//
//void pop()     
//{
//    result.result[result.num_of_result - 1] = 0;
//    result.num_of_result--;
//}
//
//void traceback(int t, int last, int flag, int num[], int n)
//{
//    int sum = 0, mul = 1;
//    if (t == n)     
//    {
//        int i = 0;
//        while (result.result[i] != 0)    
//        {
//            sum += result.result[i];
//            mul *= result.result[i];
//            i++;
//        }
//        if (sum > mul)
//            lucky += 1;
//        sum = 0;        
//        mul = 1;
//    }
//    else if (t < n)        
//    {
//        if (num[t] == last && flag == 0)        
//        {
//            traceback(t + 1, num[t], 0, num, n);        
//        }
//        else
//        {
//            append(num[t]);
//            traceback(t + 1, num[t], 1, num, n);       
//            pop();
//            traceback(t + 1, num[t], 0, num, n);        
//        }
//    }
//
//}
//
//int main(void)
//{
//    int n = 0;
//    cin >> n;      
//    int* num = new int[n];
//    for (int i = 0; i < n; i++)   
//    {
//        cin >> num[i];
//    }
//
//    sort(num, n);      
//    traceback(0, 0, 1, num, n);
//    cout << lucky << endl;
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

//int main()
//{
//    stack<char> S;
//    char x, y;
//    x = 'n'; y = 'g';
//    S.push(x); S.push('i'); S.push(y);
//    S.pop(); S.push('r'); S.push('t'); S.push(x);
//    S.pop(); S.push('s');
//    while (!S.empty())
//    {
//        x = S.top();
//        S.pop();
//        cout << x;
//    };
//    cout << y;
//}

//int main()
//{
//    queue<char> Q;
//    char x, y;
//    x = 'n'; y = 'g';
//    Q.push(x); Q.push('i'); Q.push(y);
//    Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);
//    Q.pop(); Q.push('s');
//    while (!Q.empty())
//    {
//        x = Q.front();
//        Q.pop();
//        cout << x;
//    };
//    cout << y;
//}

//class MinStack {
//private:
//    stack<int> s;
//    stack<int> min;
//public:
//
//    void push(int val) {
//        s.push(val);
//        if (min.empty())
//        {
//            min.push(val);
//        }
//        else if (!min.empty() && val <= min.top())
//        {
//            min.push(val);
//        }
//    }
//
//    void pop() {
//        if (s.top() == min.top())
//        {
//            min.pop();
//        }
//        s.pop();
//    }
//
//    int top() {
//        return s.top();
//    }
//
//    int getMin() {
//        return min.top();
//    }
//};
//int main()
//{
//    MinStack s;
//    s.push(1);
//    s.push(5);
//    s.push(0);
//    s.push(6);
//    s.push(1);
//    return 0;
//}



//bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//	// write code here
//	stack<int> sPush;
//	int i = 0;
//	int j = 0;
//	sPush.push(pushV[0]);
//	while (i < pushV.size() && j < popV.size())
//	{
//		if (sPush.empty() || sPush.top() != popV[j])
//		{
//			i++;
//			sPush.push(pushV[i]);
//		}
//		else
//		{
//			sPush.pop();
//			j++;
//		}
//	}
//	return sPush.empty();
//}
//
//int main()
//{
//	vector<int> v = { 2,1,0 };
//	vector<int> v1 = { 1,2,0 };
//	cout << IsPopOrder(v, v1);
//	return 0;
//}



//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> s;
//        int a = 0, b = 0;
//        for (auto& str : tokens)
//        {
//            if (str[0] == '+')
//            {
//                a = s.top();
//                s.pop();
//                b = s.top();
//                s.pop();
//                s.push(a + b);
//            }
//            else if (str[0] == '-' && str.size() == 1)
//            {
//                a = s.top();
//                s.pop();
//                b = s.top();
//                s.pop();
//                s.push(b - a);
//            }
//            else if (str[0] == '*')
//            {
//                a = s.top();
//                s.pop();
//                b = s.top();
//                s.pop();
//                s.push(a * b);
//            }
//            else if (str[0] == '/')
//            {
//                a = s.top();
//                s.pop();
//                b = s.top();
//                s.pop();
//                s.push(b / a);
//            }
//            else
//            {
//                s.push(stoi(str));
//            }
//        }
//        return s.top();
//    }
//};

//int main()
//{
//    Solution s;
//    vector<string> v = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
//    cout << s.evalRPN(v);
//    return 0;
//}




//int main()
//{
//    priority_queue<int> a;
//    priority_queue<int, vector<int>, greater<int> > c;
//    priority_queue<string> b;
//    for (int i = 0; i < 5; i++)
//    {
//        a.push(i);
//        c.push(i);
//    }
//    while (!a.empty())
//    {
//        cout << a.top() << ' ';
//        a.pop();
//    }
//    cout << endl;
//    while (!c.empty())
//    {
//        cout << c.top() << ' ';
//        c.pop();
//    }
//    cout << endl;
//    b.push("abc");
//    b.push("abcd");
//    b.push("cbd");
//    while (!b.empty())
//    {
//        cout << b.top() << ' ';
//        b.pop();
//    }
//    cout << endl;
//    return 0;
//}



int findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
	for (int i = k; i < nums.size(); i++)
	{
		if (nums[i] > pq.top())
		{
			pq.pop();
			pq.push(nums[i]);
		}
	}
	return pq.top();

}