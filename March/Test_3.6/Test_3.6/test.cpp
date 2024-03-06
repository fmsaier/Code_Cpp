//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//    string s;
//    getline(cin, s);
//    reverse(s.begin(), s.end());
//    cout << s;
//    return 0;
//}
//// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetMax(const string& s1, const string& s2)
{
    int len1 = s1.size();
    int len2 = s2.size();

    vector<vector<int>> msc(len1, vector<int>(len2, 0));

    int max = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; ++j)
        {
            if (s2[j] == s1[i])
            {
                if (i >= 1 && j >= 1)
                    msc[i][j] = msc[i - 1][j - 1] + 1;
                else
                    msc[i][j] = 1;

                if (msc[i][j] > max)
                    max = msc[i][j];
            }
        }
    }
    return max;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2) {
        int max = GetMax(s1, s2);
        cout << max << endl;
    }
    return 0;
}
