#define  _CRT_SECURE_NO_WARNINGS
#include "string.h"

void Test_string1()
{
    fmsaier::string s("Hello");
    char c = s[1];
    cout << c << endl;
}
void Test_string2()
{
    fmsaier::string s("Hello");
    s.push_back('!');
    s.push_back('w');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');
    fmsaier::string s2(s);
    s2 += "apple";
    /*cout << s2.size() << endl;
    for (char ch : s2)
    {
        cout << ch << " ";
    }*/
    s2.swap(s);
    cout << s.c_str() << " " << s.size() << " " << s.capacity() << endl;
    cout << s2.c_str() << " " << s2.size() << " " << s2.capacity() << endl;
}
void Test_string3()
{
    fmsaier::string s("Hello");
    cout << s.c_str() << " " << s.size() << " " << s.capacity() << endl;
    s.resize(50, 'a');
    cout << s.c_str() << " " << s.size() << " " << s.capacity() << endl;
    s.resize(4, 'a');
    cout << s.c_str() << " " << s.size() << " " << s.capacity() << endl;
}
void Test_string4()
{
    fmsaier::string s1("Hello");
    fmsaier::string s2;
    //s1 += 'a';
    cout << s2.find(s1.c_str()) << endl;
}
void Test_string5()
{
    fmsaier::string s1("Hello");
    s1.insert(0, 'a');
    cout << s1.c_str() << endl;
    fmsaier::string s(s1);
    s = s1;
}
int main()
{
    int a = 0;
	Test_string5();
	return 0;
}