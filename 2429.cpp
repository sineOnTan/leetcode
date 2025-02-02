#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int res = num1;
        cout << __builtin_popcount(num2) << " " << __builtin_popcount(num1) << endl;
        if (__builtin_popcount(num2) < __builtin_popcount(num1)) {
            for (int i = 0; i <= 30; i++) {
                if ((res & (1 << i)) != 0) res &= ~(1 << i);
                if (__builtin_popcount(num2) == __builtin_popcount(res)) return res;
            }
        } else if (__builtin_popcount(num2) > __builtin_popcount(num1)) {
            for (int i = 0; i <= 30; i++) {
                if ((res & (1 << i)) == 0) res |= (1 << i);
                if (__builtin_popcount(num2) == __builtin_popcount(res)) return res;
            }
        } else return num1;

        return 0;
    }
};