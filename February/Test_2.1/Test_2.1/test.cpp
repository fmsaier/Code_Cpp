#include <iostream>
using namespace std;
//
//class UnusualAdd {
//public:
//    int addAB(int A, int B) {
//        
//    }
//};




// 注意类名必须为 Main, 不要有任何 package xxx 信息
int func(int m, int n) {
    if ((m == 1 && n != 1) || (m != 1 && n == 1) || (m == 1 && n == 1)) {
        return m + n;
    }
    return func(m, n - 1) + func(m - 1, n);
}
int main()
{

    int a;
    int b;
    cin >> a >> b;
    cout << func(a, b);
    return 0;
}




// 64 位输出请用 printf("%lld")