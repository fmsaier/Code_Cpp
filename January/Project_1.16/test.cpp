#include <iostream>
#include <vector>
using namespace std;
//
//const int MOD = 10000009;
//
//int main() {
//    int n, d, m;
//    cin >> n >> d >> m;
//
//    // Ԥ����233���ݴ�ģֵ
//    vector<long long> pow233(d + 1);
//    pow233[0] = 1;
//    for (int k = 1; k <= d; ++k) {
//        pow233[k] = (pow233[k - 1] * 233) % MOD;
//    }
//
//    // ��ʼ������ʽ���飬1-based����
//    vector<vector<long long>> poly(n + 1, vector<long long>(d + 1, 0));
//    for (int i = 1; i <= n; ++i) {
//        int p;
//        cin >> p;
//        for (int t = 0; t <= p; ++t) {
//            cin >> poly[i][t];
//        }
//    }
//
//    // ����ÿ������
//    for (int op = 1; op <= m; ++op) {
//        int p, l, r;
//        cin >> p >> l >> r;
//        vector<long long> coeff(d + 1, 0);
//        for (int t = 0; t <= p; ++t) {
//            cin >> coeff[t];
//        }
//
//        // �ж��Ǽӻ��Ǽ�
//        bool is_add = (op % 2 == 0);
//        for (int i = l; i <= r; ++i) {
//            for (int t = 0; t <= p; ++t) {
//                if (is_add) {
//                    poly[i][t] += coeff[t];
//                }
//                else {
//                    poly[i][t] -= coeff[t];
//                }
//            }
//        }
//    }
//
//    // ����ÿ������ʽ��f(233)�����
//    for (int i = 1; i <= n; ++i) {
//        long long res = 0;
//        for (int t = 0; t <= d; ++t) {
//            res = (res + poly[i][t] * pow233[t]) % MOD;
//        }
//        res = (res % MOD + MOD) % MOD; // ȷ������Ǹ�
//        cout << res << " ";
//    }
//
//    return 0;
//}




class B
{
public:

};

class A
{
public:
	operator int()
	{
		return 1;
	}
};

int main()
{
	A a;
	cout << (int)a << endl;
	return 0;
}