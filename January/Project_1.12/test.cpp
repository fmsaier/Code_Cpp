#include <iostream>
#include <string>

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
        Data d;
        d.Test2();
        // Test2(); 静态没有this访问不了非静态
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

    string s = "hello";
    cout << s.size() << endl;

    char str[] = "hello";
    const char* pstr = "hellp";

    const char* ch = s.c_str() + s.size();
    cout << *(pstr + 5) << endl;

    for (char ch : s)
    {
        cout << ch << endl;
    }

    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << endl;
        it++;
    }
}
//namespace bit
//
//{
//
//    class string
//
//    {
//
//        friend ostream& operator<<(ostream& _cout, const bit::string& s);
//
//        friend istream& operator>>(istream& _cin, bit::string& s);
//
//    public:
//
//        typedef char* iterator;
//
//    public:
//
//        string(const char* str = "")；
//
//            string(const string& s)；
//
//            string& operator=(const string& s)；
//
//            ~string()；
//
//
//
//            //////////////////////////////////////////////////////////////
//
//            // iterator
//
//            iterator begin()；
//
//            iterator end()；
//
//
//
//            /////////////////////////////////////////////////////////////
//
//            // modify
//
//            void push_back(char c);
//
//        string& operator+=(char c);
//
//        void append(const char* str);
//
//        string& operator+=(const char* str);
//
//        void clear();
//
//        void swap(string& s);
//
//        const char* c_str()const;
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        // capacity
//
//        size_t size()const
//
//            size_t capacity()const
//
//            bool empty()const
//
//            void resize(size_t n, char c = '\0');
//
//        void reserve(size_t n);
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        // access
//
//        char& operator[](size_t index);
//
//        const char& operator[](size_t index)const;
//
//
//
//        /////////////////////////////////////////////////////////////
//
//        //relational operators
//
//        bool operator<(const string& s);
//
//        bool operator<=(const string& s);
//
//        bool operator>(const string& s);
//
//        bool operator>=(const string& s);
//
//        bool operator==(const string& s);
//
//        bool operator!=(const string& s);
//
//
//
//        // 返回c在string中第一次出现的位置
//
//        size_t find(char c, size_t pos = 0) const;
//
//        // 返回子串s在string中第一次出现的位置
//
//        size_t find(const char* s, size_t pos = 0) const;
//
//        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
//
//        string& insert(size_t pos, char c);
//
//        string& insert(size_t pos, const char* str);
//
//
//
//        // 删除pos位置上的元素，并返回该元素的下一个位置
//
//        string& erase(size_t pos, size_t len);
//
//    private:
//
//        char* _str;
//
//        size_t _capacity;
//
//        size_t _size;
//
//    }
//
//}；