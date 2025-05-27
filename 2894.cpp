#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % m != 0) num1 += i;
        }

        int num2 = 0;
        for (int i = 0; i < m; i++) {
            if (i % n == 0) num2 += i;
        }

        return num1 - num2;
    }
};