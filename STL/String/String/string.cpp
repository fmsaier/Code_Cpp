#include "string.h"
#include <string>
namespace fmsaier
{
    size_t string::npos = -1;

    string::string(const char* str)
    {
        _size = strlen(str);
        _str = new char[_size + 1];
        strcpy(_str, str);
        _capacity = _size;
    }
    //写法一
    /*string::string(const string& s)
    {
        _str = new char[s._size + 1];
        strcpy(_str, s._str);
        _size = s._size;
        _capacity = s._capacity;
    }*/
    //写法二
    string::string(const string& s)
    {
        string tmp(s._str);
        swap(tmp);
    }
    //写法一
    string& string::operator=(const string& s)
    {
        _str = new char[s._size + 1];
        strcpy(_str, s._str);
        _size = s._size;
        _capacity = s._capacity;
        return *this;
    }
    //写法二
    string& string::operator=(string s)
    {
        swap(s);
        return *this;
    }
    string::~string()
    {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }
    void string::push_back(char c)
    {
        if (_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
            char* tmp = new char[newcapacity + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        _str[_size] = c;
        _size++;
        _str[_size] = '\0';
    }
    string& string::operator+=(char c)
    {
        push_back(c);
        return *this;
    }
    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }
    string& string::operator+=(const char* str)
    {
        append(str);
        return *this;
    }
    void string::clear()
    {
        _size = 0;
        _str[0] = '\0';
    }
    void string::swap(string& s)
    {
        std::swap(*this, s);
    }
    void string::resize(size_t n, char c)
    {
        if (n <= _size)
        {
            _size = n;
            _str[n] = '\0';
        }
        else if(n > _size && n <= _capacity)
        {
            memset(_str + _size, c, n - _size - 1);
            _size = n;
            _str[n] = '\0';
        }
        else if (n > _capacity)
        {
            reserve(n);
            memset(_str + _size, c, n - _size);
            _size = n;
            _str[n] = '\0';
        }
    }
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {       
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }
    size_t string::find(char c, size_t pos) const
    {
        assert(pos < _size);
        for (int i = pos; i < _size; i++)
        {
            if (_str[i] == c)
                return i;
        }
        return npos;
    }
    size_t string::find(const char* s, size_t pos) const
    {
        assert(pos < _size);
        if (strstr(_str + pos, s) == nullptr)
            return npos;

        return strstr(_str + pos, s) - _str;
    }
    string& string::insert(size_t pos, char c)
    {
        assert(pos < _size);
        if (_size == _capacity)
        {
            size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
            char* tmp = new char[newcapacity + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = newcapacity;
        }
        size_t end = _size + 1;
        while (end > pos)
        {
            _str[end] = _str[end - 1];
            end--;
        }
        _str[pos] = c;
        _size++;
        return *this;
    }
    string& string::insert(size_t pos, const char* str)
    {
        assert(pos < _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        int end = _size;
        while (end >= (int)pos)
        {
            _str[end + len] = _str[end];
            --end;
        }
        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }
    string& string::erase(size_t pos, size_t len)
    {
        if (len == npos || pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }
}
