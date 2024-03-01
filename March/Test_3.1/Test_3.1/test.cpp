////#include <iostream>
////using namespace std;
////
////
////int isOKNum(int num)
////{
////	int sum = 0;
////	for (int i = 1; i <= num / 2; i++)
////	{
////		if (num % i == 0)
////		{
////			sum += i;
////		}
////	}
////	if (sum == num)
////		return 1;
////	return 0;
////}
////int main()
////{
////	int n;
////	cin >> n;
////	int count = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		count += isOKNum(i);
////	}
////	cout << count << endl;
////	return 0;
////}
////// 64 位输出请用 printf("%lld")
//
//
//
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//string FindMax(const string& line) {
//    if (line.find("joker JOKER") != string::npos)
//        return "joker JOKER";
//    int dash = line.find('-');
//    //分开两手牌
//    string car1 = line.substr(0, dash);
//    string car2 = line.substr(dash + 1);
//    //获取两手牌的张数
//    int car1_cnt = count(car1.begin(), car1.end(), ' ') + 1;
//    int car2_cnt = count(car2.begin(), car2.end(), ' ') + 1;
//    //获取两手牌的各自第一张牌
//    string car1_first = car1.substr(0, car1.find(' '));
//    string car2_first = car2.substr(0, car2.find(' '));
//    if (car1_cnt == car2_cnt) { //两手牌的类型相同
//        string str = "345678910JQKA2jokerJOKER";
//        if (str.find(car1_first) > str.find(car2_first))
//            return car1;
//        return car2;
//    }
//    if (car1_cnt == 4) //说明是炸弹
//        return car1;
//    else if (car2_cnt == 4)
//        return car2;
//    return "ERROR";
//}
//int main() {
//    string line, res;
//    while (getline(cin, line)) {
//        res = FindMax(line);
//        cout << res << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;



class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        int dest = arr.size() - 1;
        int cur = 0;
        while (count < arr.size())
        {
            if (arr[cur] == 0)
            {
                count++;
            }
            count++;
            if (count >= arr.size())
                break;
            cur++;
        }
        //cout << cur <<endl;
        if (arr[cur] == 0 && count > arr.size())
        {
            arr[arr.size() - 1] = 0;
        }
        //if(arr[--cur] == 0)
        //    cur--;
        while (cur >= 0)
        {
            if (arr[cur] == 0 && count == arr.size())
            {
                arr[dest--] = 0;
            }
            count > arr.size() ? count = arr.size() : 0;
            arr[dest--] = arr[cur--];
        }
        
    }
};
int main()
{
	/*deque<int> cont = { 1, 2, 3, 4, 5 };
	deque<int>::iterator iter, tempIt;
	for (iter = cont.begin(); iter != cont.end();)
	{
		tempIt = iter;
		++iter;
		cont.erase(tempIt);
	}*/
    Solution s;
    vector<int> v = { 1,0,2,3,0,4,5,0 };
    // 8 4 5 0 0 0 0 0
    s.duplicateZeros(v);
    return 0;
}