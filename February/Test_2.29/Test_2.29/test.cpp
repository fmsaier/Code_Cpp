//#include <iostream>
//
//using namespace std;
//
//class Person
//{
//public:
//	int name;
//};
//class Student:public Person
//{
//
//};
//
//int main()
//{
//	Student s;
//	Person p1 = s;
//	Person* p = new Student;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    size_t a = 0;
//    while (cin >> a)
//    {
//        int count = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            count += a & 1;
//            a = a >> 1;
//        }
//        cout << count << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] * right[i] == 0)
                sum += left[i] + right[i];
            else {
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left_min, left[i]);
                right_min = min(right_min, right[i]);
            }
        }
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};