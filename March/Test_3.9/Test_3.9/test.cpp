//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;

//class Gift {
//public:
//    int getValue(vector<int> gifts, int n) 
//    {
//        sort(gifts.begin(), gifts.end());
//        if (gifts[n / 2] == gifts[n / 2 - 1])
//            return gifts[n / 2];
//        else
//            return 0;
//    }
//};


//dp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(const string& s1, const string& s2)
{
    if (s1.empty() || s2.empty())
        return max(s1.size(), s2.size());

    int len1 = s1.size();
    int len2 = s2.size();

    vector<vector<int >> f(len1 + 1, vector<int>(len2 + 1, 0));
    //初始化距离
    for (int i = 0; i <= len1; i++)
        f[i][0] = i;
    for (int j = 0; j <= len2; ++j)
        f[0][j] = j;

    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s2[j - 1] == s1[i - 1])
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                //由于字符相同，距离不发生变化
                f[i][j] = min(f[i - 1][j - 1], f[i][j]);
            }
            else
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                //由于字符不相同，距离+1
                f[i][j] = min(f[i - 1][j - 1] + 1, f[i][j]);
            }
        }
    }
    return f[len1][len2];
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        cout << minDistance(s1, s2) << endl;
    }
    return 0;
}

// 64 位输出请用 printf("%lld")
//abefgasd
//abcdef