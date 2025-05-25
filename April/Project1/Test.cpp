#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s = 1, w = 0;
    long long max_attack = -1, current_stage = 0;
    bool alive = true;
    for (int i = 0; i < n; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        int s1 = s, w1 = w;
        bool valid1 = false;
        if (c1 == 1000 || c1 == -1000)
        {
            if (c1 == 1000) w1 = min(w + 1, 6);
            else if (c1 == -1000) w1 = max(w - 1, 0);
            valid1 = (s1 > 0);
        }
        else
        {
            s1 += c1;
            valid1 = (s1 > 0);
        }
        int s2 = s, w2 = w;
        bool valid2 = false;
        if (c2 == 1000 || c2 == -1000)
        {
            if (c2 == 1000) w2 = min(w + 1, 6);
            else if (c2 == -1000) w2 = max(w - 1, 0);
            valid2 = (s2 > 0);
        }
        else 
        {
            s2 += c2;
            valid2 = (s2 > 0);
        }
        long long attack1 = valid1 ? (s1 * (w1 + 1)) : -1;
        long long attack2 = valid2 ? (s2 * (w2 + 1)) : -1;
        if (valid1 || valid2)
        {
            if (valid1 && (!valid2 || attack1 >= attack2))
            {
                s = s1;
                w = w1;
                max_attack = max(max_attack, attack1);
            }
            else if (valid2 && (!valid1 || attack2 >= attack1)) {
                s = s2;
                w = w2;
                max_attack = max(max_attack, attack2);
            }
            else if (attack1 == attack2 && valid2 && valid1)
            {
                if (s1 > s2)
                {
                    s = s1;
                    w = w1;
                    max_attack = max(max_attack, attack1);
                }
                else
                {
                    s = s2;
                    w = w2;
                    max_attack = max(max_attack, attack2);
                }
            }
            current_stage++;
        }
        else if(!valid1 && !valid2){
            alive = false;
            break;
        }
    }
    if (alive)
    {
        cout << "1 " << max_attack << endl;
    }
    else {
        cout << "0 " << (current_stage + 1) << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")