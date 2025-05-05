#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    public:
        int numTilings(int n) {
            const int N = 1e3 + 5;
            long long upper[N];
            long long lower[N];
            long long complete[N];

            upper[0] = 0;
            lower[0] = 0;
            complete[0] = 1;

            complete[1] = 1;

            for (int i = 2; i <= n; i++) {
                upper[i] = lower[i - 1] + complete[i - 2];
                lower[i] = upper[i - 1] + complete[i - 2];
                complete[i] = upper[i - 1] + lower[i - 1] + complete[i - 1] + complete[i - 2];
                upper[i] %= MOD;
                lower[i] %= MOD;
                complete[i] %= MOD;
            }

            return complete[n] % MOD;;
        }
    };