//#include <iostream>
//
//class Date
//{
//private:
//	int _year = 1;
//	int _month = 1;
//public:
//	Date()
//	{
//		_year = 10;
//		_month = 5;
//	}
//};
//class Test
//{
//private:
//	Date _d;
//	int _size;
//
//public:
//	Test()
//	{
//		_size = 1;
//		//_d = new Date(1, 1, 1);
//	}
//};
//
//int main()
//{
//	Test t1;
//	return 0;
//}


#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 0, i = 0;
    bool isBig = false, isSmall = false;
    int* arr = new int[n];
    while (count < n)
    {
        cin >> arr[count++];
    }
    count = 1;
    while (i < n - 1)
    {
        if (arr[i] < arr[i + 1])
        {
            i++;
            isSmall = true;
            if (isBig)
            {
                count++;
                isBig = false;
                isSmall = false;
            }


        }
        else if (arr[i] > arr[i + 1])
        {
            i++;
            isBig = true;
            if (isSmall)
            {
                count++;
                isBig = false;
                isSmall = false;
            }
        }
        else
        {
            i++;
        }
    }
    delete[] arr;
    printf("%lld", count);
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string s;
//	getline(cin,s);
//	reverse(s.begin(), s.end());
//	string::iterator it = s.begin();
//	int count = 0;
//	for (int i = 0; i < s.size() + 1; i++)
//	{
//		if (s[i] == ' ' || s[i] == '\0')
//		{
//			reverse(it, it+count);
//			if (it + count != s.end())
//			{
//				it += count + 1;
//				i++;
//				count = 0;
//			}
//		}
//		count++;
//	}
//	cout << s;
//}
//// 64 位输出请用 printf("%lld")