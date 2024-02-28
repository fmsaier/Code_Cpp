//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int year, month, day, time = 0;
//	cin >> year >> month >> day;
//	int monDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		monDay[2] = 29;
//	}
//	for (int i = 0; i < month; i++)
//	{
//		time += monDay[i];
//	}
//	time += day;
//
//
//	cout << time << endl;
//	return 0;
//}
//// 64 位输出请用 printf("%lld")






#include <iostream>
using namespace std;

int lucky = 0;      
struct result_list
{
    int result[100];
    int num_of_result = 0;
}result;        

void sort(int num[], int n)        
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i, tmp;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        tmp = num[i];
        num[i] = num[min];
        num[min] = tmp;
    }
}

void append(int n_append)       
{
    result.result[result.num_of_result] = n_append;
    result.num_of_result++;
}

void pop()     
{
    result.result[result.num_of_result - 1] = 0;
    result.num_of_result--;
}

void traceback(int t, int last, int flag, int num[], int n)
{
    int sum = 0, mul = 1;
    if (t == n)     
    {
        int i = 0;
        while (result.result[i] != 0)    
        {
            sum += result.result[i];
            mul *= result.result[i];
            i++;
        }
        if (sum > mul)
            lucky += 1;
        sum = 0;        
        mul = 1;
    }
    else if (t < n)        
    {
        if (num[t] == last && flag == 0)        
        {
            traceback(t + 1, num[t], 0, num, n);        
        }
        else
        {
            append(num[t]);
            traceback(t + 1, num[t], 1, num, n);       
            pop();
            traceback(t + 1, num[t], 0, num, n);        
        }
    }

}

int main(void)
{
    int n = 0;
    cin >> n;      
    int* num = new int[n];
    for (int i = 0; i < n; i++)   
    {
        cin >> num[i];
    }

    sort(num, n);      
    traceback(0, 0, 1, num, n);
    cout << lucky << endl;

    return 0;
}
