#include <iostream>

using namespace std;

class Time
{
    friend class Data;
};

class Data
{
    friend ostream& operator<< (ostream& _cout, Data& d);
private:
    const static int a = 0;
    int year;
    int month = 1;
public:
    explicit Data()
        : year(1)
    {
        cout << month << endl;
    }
    Data(const Data& d)
    {
        cout << "Data(const Date& d)" << endl;
    }

    Data& operator=(const Data& d)
    {
        cout << "Data& operator=(const Data& d)" << endl;
        return *this;
    }
    ~Data() {}

    Data* operator& ()
    {
        return this;
    }

    const Data* operator& () const
    {
        return this;
    }

    static void Test1()
    {

    }

    void Test2()
    {
        Test1();
    }
};

ostream& operator<< (ostream& _cout, Data& d)
{
    return _cout;
}

int main()
{
    Data d1;
    // Data d3(); 不认识是什么，就没运行这行
    Data(); //匿名
    Data d2 = d1;
    int* p = new int[3] {1, 2, 3};
}