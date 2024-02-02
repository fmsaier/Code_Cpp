#include <iostream>
#include <vector>

using namespace std;

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1)
                return true;
        }
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == 1 &&board[1][i] ==1&& board[2][i] == 1)
                return true;
        }
        if (board[0][0] ==1&& board[1][1] ==1&& board[2][2] == 1)
            return true;
        if (board[0][2] ==1&& board[1][1] ==1&& board[2][0] == 1)
            return true;
        return false;
    }
};

int main()
{
    Board b;

    vector<int> v1 = { 0,0,0 };
    vector<int> v2 = { 0,0,0 };
    vector<int> v3 = { 1,-1,0 };
    vector <vector<int>> v = { v1,v2,v3 };
    cout << b.checkWon(v);
}

//#include <string>
//
//int main()
//{
//    string s;
//    cin >> s;
//    int score = 0;
//    bool isBig = false;
//    bool isSmall = false;
//    int dCount = 0;
//    int aCount = 0;
//    if (s.size() <= 4)
//        score = 5;
//    else if (s.size() < 8)
//        score = 10;
//    else
//        score = 25;
//    for (auto ch : s)
//    {
//        if (ch >= 'a' && ch <= 'z')
//            isSmall = true;
//        else if (ch >= 'A' && ch <= 'Z')
//            isBig = true;
//        else if (isdigit(ch))
//            dCount++;
//        else
//            aCount++;
//    }
//    if (isSmall && isBig)
//        score += 20;
//    else if ((!isSmall && isBig) || (isSmall && !isBig))
//        score += 10;
//    if (dCount == 1)
//        score += 10;
//    else if (dCount > 1)
//        score += 20;
//    if (aCount == 1)
//        score += 10;
//    else if (aCount > 1)
//        score += 25;
//    if (isBig && isSmall && dCount && aCount)
//        score += 5;
//    else if (dCount && aCount && (!isSmall && isBig) || (isSmall && !isBig))
//        score += 3;
//    else if (dCount && (!isSmall && isBig) || (isSmall && !isBig))
//        score += 2;
//   /* 90VERY_SECURE
//      80  SECURE
//        70VERY_STRONG
//        60STRONG
//        50AVERAGE
//        25WEAK
//        0VERY_WEAK*/
//    if (score >= 90)
//        cout << "VERY_SECURE";
//    else if (score >= 80)
//        cout << "SECURE";
//    else if (score >= 70)
//        cout << "VERY_STRONG";
//    else if (score >= 60)
//        cout << "STRONG";
//    else if (score >= 50)
//        cout << "AVERAGE";
//    else if (score >= 25)
//        cout << "WEAK";
//    else
//        cout << "VERY_WEAK";
//    return 0;
//}
//// 64 位输出请用 printf("%lld")