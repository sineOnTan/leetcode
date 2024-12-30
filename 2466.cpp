#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        const int N = 100010;
        const int mod = 1000000000 + 7;

        long long a[N];
        a[0] = 1;
        for (int i = 1; i <= high; i++) {
            a[i] = 0;
            if (i >= zero) a[i] += a[i - zero];
            if (i >= one) a[i] += a[i - one];
            a[i] %= mod;
        }
        int res = 0;
        for (int i = low; i <= high; i++) {
            res += a[i];
            res %= mod;
        }
        return res;
    }
};