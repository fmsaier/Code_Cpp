#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

namespace fmsaier
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const fmsaier::string& s);
        friend istream& operator>>(istream& _cin, fmsaier::string& s);

   
    public:
        string(const char* str = "")
        {
            _size = strlen(str);
            _str = new char[_size + 1];
            strcpy(_str, str);
            _capacity = _size;
        }   
        string(const string& s)
        {
            _str = new char[s._size + 1];
            strcpy(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;
        }
        string& operator=(const string& s)
        {
            _str = new char[s._size + 1];
            strcpy(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;
            return *this;
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        //////////////////////////////////////////////////////////////
        // iterator
    public:
        typedef char* iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear();

        void swap(string& s);

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

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);

        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            assert(index <= _size);
            return *(_str + index);
        }

        const char& operator[](size_t index)const
		{
            assert(index <= _size);
			return *(_str + index);
		}

        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s);

        bool operator<=(const string& s);

        bool operator>(const string& s);

        bool operator>=(const string& s);

        bool operator==(const string& s);

        bool operator!=(const string& s);

        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);

        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len);

         private:
             char* _str;
             size_t _capacity;
             size_t _size;
             static size_t npos;

    };
    size_t string::npos = -1;
    void Test_string1()
    {
        string s("Hello");
        char c = s[1];
        cout << c << endl;
    }
};