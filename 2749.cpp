#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long num = num1;
        for (int i = 1; num >= 0; i++) {
            num -= num2;
            int count = 0;
            for (int i = 0; i < 60; i++) {
                if ((long long)1 << i && num != 0) count += i + 1;
            }
            if (__builtin_popcount(num) <= i and count <= i and num >= i) return i;
        }
        return -1;
    }
};

