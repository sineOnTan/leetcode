#include <bits/stdc++.h>
using namespace std;

const int MOD = 10e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int N = 30;
        long long a[N];
        for (int i = 0; i < N; i++) a[i] = 0;
        for (auto i : s) a[i - 'a']++;
        for (int i = 0; i <= 'z' - 'a'; i++) {
            char c = i + 'a';
            cout << a[i] << " " << c << endl;
        }

        for (int z = 0; z < t; z++) {
            for (int i = N - 3; i >= 0; i--) {
                a[i + 1] = a[i] % MOD;
            }
            a[N - 1] = 0;
            a[0] = 0;
            a[0] += a['z' - 'a' + 1];
            a[1] += a['z' - 'a' + 1];
        }
        long long res = 0;
        for (int i = 0; i <= 'z' - 'a'; i++) {
            res += a[i];
            res %= MOD;
        }
        return res;
    }
};