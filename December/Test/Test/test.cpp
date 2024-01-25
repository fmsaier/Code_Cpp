#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 3 * n;
    int i = 0;
    int tmp;
    int* intArr = (int*)malloc(sizeof(int) * n);
    while (count--)
    {
        cin >> intArr[i++];
    }
    for (int i = 0; i < 3 * n; i++)
    {
        for (int j = 0; j < 3 * n - i - 1; j++)
        {
            if (intArr[j] < intArr[j + 1])
            {
                tmp = intArr[j];
                intArr[j] = intArr[j + 1];
                intArr[j + 1] = tmp;
            }
        }
    }
    int a = 0;
    int k = n;
    if (n == 0)
        cout << 0 << endl;
    else
    {
        while (k--)
        {
            a += intArr[n + k];
        }

    }
    cout << a << endl;
}


//上面代码的第36行改成这个-> quicksort(arr, 0, 3 * n - 1);
