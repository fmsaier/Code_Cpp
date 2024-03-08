//#include <iostream>
//using namespace std;
//int isOK(int a)
//{
//
//		int sum = 0;
//		for (int j = 1; j <= a - 1; j++) {//从1~a-1枚举j，如果是j是a的因数，因数之和加上j
//			if (a % j == 0)  sum += j;
//		}
//
//	
//
//	return sum == a;
//}
//int main()
//{
//	int number = 0;
//	cin >> number;
//	int count = 0;
//	int i = 1;
//	while (i < number)
//	{
//		count += isOK(i);
//		i++;
//	}
//	cout << i;
//}




//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	bool isActive = false;
//	vector<int> v;
//	vector<int> vv;
//	vector<vector<int>> vvv;
//	int count = 0;
//	int n = 0, k = 0;
//	int j = 0;
//	cin >> count;
//	while (count--)
//	{
//		cin >> n >> k;
//		vv.resize(2 * n);
//		j = 2 * n;
//		while (j--)
//		{
//			int tmp = 0;
//			cin >> tmp;
//			v.push_back(tmp);
//		}
//		while (k--)
//		{
//			int index = 0;
//			for (int i = 0; i < n; i++)
//			{
//				if (!isActive)
//				{
//					vv[index++] = v[i];
//					vv[index++] = v[i + n];
//				}
//				else
//				{
//					v[index++] = vv[i];
//					v[index++] = vv[i + n];
//				}
//			}
//			isActive = !isActive;
//		}
//		if (isActive)
//		{
//			vvv.push_back(vv);
//
//		}
//		else
//		{
//			vvv.push_back(v);
//		}
//		v.clear();
//		vv.clear();
//		isActive = false;
//	}
//	for (int i = 0; i < vvv.size(); i++)
//	{
//		for (int j = 0; j < vvv[i].size(); j++)
//		{
//			if (j + 1 == vvv[i].size())
//			{
//				cout << vvv[i][j] << endl;
//				continue;
//			}
//			cout << vvv[i][j] << " ";
//
//		}
//	}
//	return 0;
//}
//// 64 位输出请用 printf("%lld")


#include <iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string cmd;
    while (cin >> n >> cmd)
    {
        int num = 1, first = 1;
        if (n <= 4)
        {
            for (int i = 0; i < cmd.size(); ++i)
            {
                if (num == 1 && cmd[i] == 'U')
                    num = n;
                else if (num == n && cmd[i] == 'D')
                    num = 1;
                else if (cmd[i] == 'U')
                    num--;
                else
                    num++;

            }
            for (int i = 1; i <= n; ++i)
                cout << i << " ";
            cout << endl;
            cout << num << endl;
        }
        else {
            for (int i = 0; i < cmd.size(); ++i)
            {
                if (first == 1 && num == 1 && cmd[i] == 'U')
                {
                    first = n - 3;
                    num = n;
                }
                else if (first == n - 3 && num == n && cmd[i] == 'D')
                {
                    first = num = 1;
                }
                else if (first != 1 && num == first && cmd[i] == 'U')
                {
                    first--;
                    num--;
                }
                else if (first != n - 3 && num == first + 3 && cmd[i] == 'D')
                {
                    first++;
                    num++;
                }
                else if (cmd[i] == 'U')
                    num--;
                else
                    num++;
            }
            for (int i = first; i <= first + 3; ++i)
                cout << i << " ";
            cout << endl;
            cout << num << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
