//#include <iostream>
//
//using namespace std;
////
//////class A
//////{
//////
//////};
//////class B : public A
//////{
//////
//////};
////
////class Person
////{
////public:
////	Person()
////	{}
////	virtual void Test(int x =1)
////	{
////		cout << "Person()" << endl;
////	}
////	virtual ~Person()
////	{
////		cout << "~Person()" << endl;
////	}
////	int _a = 0; 
////};
////class Teacher : public Person
////{
////public:
////	Teacher()
////	{}
////	virtual void Test()
////	{
////		cout << "Teacher()" << endl;
////		_b = 2;
////	}
////	virtual ~Teacher()
////	{
////		cout << "~Teacher()" << endl;
////	}
////	int _b = 1;
////};
//////class Student : virtual public Person
//////{
//////public:
//////	Student()
//////	{}
//////	virtual void Test()
//////	{
//////		cout << "Student()" << endl;
//////	}
//////	int _c = 2;
//////};
//////class CLX : public Teacher ,public Student
//////{
//////
//////	int _d = 4;
//////};
////
////int main()
////{
////	Teacher t;
////	cout << sizeof(Teacher) << endl;
////	Person p = t;
////	/*CLX c;*/
////	//Teacher t;
////	//Person p1;
////	//Person* p2 = &p1;
////	//p2->Test();
////	//Person* p = &t;
////	//p->Test();
////	//return 0;
////}
//
//
//
//class A
//{
//public:
//    virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//    virtual void test() { this->func(); }
//};
//
//class B : public A
//{
//public:
//    void func(int v = 100) { std::cout << "B->" << v << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//    B* p = new B;
//    p->test();
//    return 0;
//}
////A: A->0
//// B : B->1 
//// C : A->1 
//// D : B->0 



#include<iostream>
using namespace std;

//概念法
int calcNumber_1(int n)
{
    int sum = 0;
    while (n > 1)
    {
        int res = n / 3; //所能兑换的个数
        int left = n % 3; //遗下的个数
        sum += res;
        n = left + res;
        if (n == 2)
        {
            sum++;
            break;
        }
    } r
        eturn sum;
}

//取巧法
int calcNumber(int n)
{
    return n / 2;
}

int main()
{
    int n, res;
    while (cin >> n)
    {
        if (n == 0)
            break;
        res = calcNumber(n);
        cout << res << endl;
    }
    return 0;
}




#include<iostream>
#include<string>
#include<vector>
using namespace std;

string Getstr(string& amp; s1, string& amp; s2)
{
    if (s1.size() > s2.size())
        swap(s1, s2);

    int l1 = s1.size();
    int l2 = s2.size();

    vector<vector<int>> a(l1 + 1, vector<int>(l2 + 1, 0));

    int start = 0, max = 0;

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s2[j - 1] == s1[i - 1])
                a[i][j] = a[i - 1][j - 1] + 1;

            if (a[i][j] > max)
            {
                max = a[i][j];
                start = i - max;
            }
        }
    }
    return s1.substr(start, max);
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        string substr = Getstr(s1, s2);
        cout << substr << endl;
    }
    return 0;
}
