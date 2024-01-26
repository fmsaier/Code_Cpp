//#include "test.h";
//
//ostream& operator<<(ostream& out, MyClass& c)
//{
//	out << c.a << c.b;
//	return out;
//}
//const int main()
//{
//	MyClass c1,c2;
//	//MyClass::operator<<
//	//c1.operator<<(cout, c1);
//	/*cout << c1;
//	c1 == c2;*/
//	cout << c1;
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;


int main() {
    int a, b;
    bool isNegative = false;
    int c;
    vector<int> v;
    cin >> a >> b;
    if (a == 0)
    {
        cout << 0;
        return 0;
    }
    else if (a < 0)
    {
        isNegative = true;
        a = -a;
    }
    while (a / b > b)
    {
        c = a / b;
        c = a - (c * b);
        v.push_back(c);
        a = a / b;
    }
    c = a / b;
    c = a - (c * b);
    v.push_back(c);
    a = a / b;
    v.push_back(a);
    for (int i = v.size()-1;i >= 0; i--)
    {
        if (isNegative)
        {
            cout << '-';
        }
        if (b > 9 && v[i]>9)
        {
            switch (v[i])
            {
            case 10:
                cout << 'A';
                break;
            case 11:
                cout << 'B';
                break;
            case 12:
                cout << 'C';
                break;
            case 13:
                cout << 'D';
                break;
            case 14:
                cout << 'E';
                break;
            case 15:
                cout << 'F';
                break;
            }
        }
        else
        {
            cout << v[i];
        }

    }
    return 0;
}
// 64 位输出请用 printf("%lld")


//#include <iostream>
//using namespace std;
//
//int main() {
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int e, f, g;
//	bool isInt = false;
//	int k = -30;
//	isInt = ((a + c) %2 == 0);
//	if (isInt)
//	{
//		e = (a + c) / (float)2;
//		f = c - e;
//		g = d - f;
//		if (e < 0 || f < 0 || g < 0)
//			cout << "No";
//		else
//			cout << e << " " << f << " " << g << endl;
//	}
//	else
//	{
//		cout << "No";
//	}
//	return 0;
//}
