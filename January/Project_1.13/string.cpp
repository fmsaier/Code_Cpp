#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace fmsaier
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const fmsaier::string& s);
        friend istream& operator>>(istream& _cin, fmsaier::string& s);

    private:
        char* _str;
        size_t _capacity;
        size_t _size;

    public:
        typedef char* iterator;
        typedef const char* const_iterator;

    public:
        string(const char* str = "")
        {
            _capacity = _size = strlen(str);
            _str = new char[_size + 1];
            strcpy(_str, str);
        }
        string(const string& s)
        {
            string tmp(s._str);
            swap(tmp);
        }
        string& operator=(string s)
        {
            swap(s);
            return *this;
        }
        ~string()
        {
            _size = _capacity = 0;
            delete[] _str;
            _str = nullptr;
        }

        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }

        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c)
        {

        }

        string& operator+=(char c)
        {

        }

        void append(const char* str)
        {

        }

        string& operator+=(const char* str)
        {

        }

        void clear()
        {
            _size = _capacity = 0;
            _str[0] = '\0';
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }

        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {
            return _size;
        }
        size_t capacity()const
        {
            return _capacity;
        }
        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {

        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* newStr = new char[n + 1];
                strcpy(newStr, _str);
                delete[] _str;
                _str = newStr;
                _capacity = n;
            }
        }

        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            return *(_str + index);
        }

        const char& operator[](size_t index)const
        {
            return *(_str + index);
        }

        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s)
        {

        }

        bool operator<=(const string& s)
        {

        }

        bool operator>(const string& s)
        {

        }

        bool operator>=(const string& s)
        {

        }

        bool operator==(const string& s)
        {

        }

        bool operator!=(const string& s)
        {

        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {

        }

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {

        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            if (_size == _capacity)
            {
                int newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
                reserve(newCapacity);
            }
            strcpy(_str + pos + 1, _str + pos);
            _str[pos] = c;
            _size++;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {

        }

        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {

        }
    };
}


ostream& operator<<(ostream& _cout, const fmsaier::string& s)
{
    return _cout;
}

istream& operator>>(istream& _cin, fmsaier::string& s)
{
    return _cin;
}

int main()
{
    fmsaier::string s("hello");
    for (char ch : s)
    {
        cout << ch << endl;
    }
    return 0;
}