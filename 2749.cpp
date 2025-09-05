#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; num1 >= 0; i++) {
            num1 -= num2;
            cout << __builtin_popcount(num1) << " " << i << endl;
            if (__builtin_popcount(num1) == i) return i;
        }
        return -1;
    }
};

