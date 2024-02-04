#include <iostream>
#include <vector>

using namespace std;

//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		return (m << j) + n;
//	}
//};


#include <iostream>
using namespace std;

void SuNum(vector<int>& v)
{
    int count = 0;
    for (int i = 3; i < 550; i++)
    {
        for (int j = 2; j < i / 2; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (!count)
        {
            v.push_back(i);
        }
        count = 0;
    }
}
int main() 
{
    int a;
    cin >> a;
    vector<int> v(1,2);
    SuNum(v);
    int b = a / 2;
    int c = b;
    int count = 0;
    while (b>1)
    {
        for (int i : v)
        {
            if (i == c)
            {
                count++;
            }
            if (i == b)
            {
                count++;
            }
        }
        if (count == 2)
        {
            break;
        }
        count = 0;
        c++;
        b--;
    }
    cout << b  << endl << c;
    return 0;
}
// 64 位输出请用 printf("%lld")