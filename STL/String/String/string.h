#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using std::ostream;
using std::istream;
using std::endl;
using std::cout;

namespace fmsaier
{
    class string
    {
    private:
        char* _str = nullptr;
        size_t _capacity = 0;
        size_t _size = 0;
        static size_t npos;

    public:
        string(const char* str = "");
        string(const string& s); 
        //string(string&& s);
        //string& operator=(const string& s);
        string& operator=(string s);
        //string& operator=(string&& s);
        ~string();

        //////////////////////////////////////////////////////////////
        // iterator
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
        iterator begin()
        {
            return _str;
        }
        const_iterator begin() const
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        const_iterator end() const
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
        bool operator<(const string& s)
        {
            return strcmp(_str, s._str) < 0;
        }
        bool operator<=(const string& s)
        {
            return strcmp(_str, s._str) <= 0;
        }
        bool operator>(const string& s)
        {
            return strcmp(_str, s._str) > 0;
        }
        bool operator>=(const string& s)
        {
            return strcmp(_str, s._str) >= 0;
        }
        bool operator==(const string& s)
        {
            return strcmp(_str, s._str) == 0;
        }
        bool operator!=(const string& s)
        {
            return strcmp(_str, s._str) != 0;
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const;
        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);

        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len = npos);

        friend ostream& operator<<(ostream& _cout, const fmsaier::string& s);
        friend istream& operator>>(istream& _cin, fmsaier::string& s);
    };

    ostream& operator<<(ostream& out, const string& s)
    {
        for (auto ch : s)
        {
            out << ch;
        }

        return out;
    }

    istream& operator>>(istream& in, string& s)
    {
        s.clear();
        char buff[128];
        char ch = in.get();
        int i = 0;
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 127)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = in.get();
        }

        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }
};
