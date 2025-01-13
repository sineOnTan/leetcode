#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        const int N = 30;
        int a[N];

        for (int i = 0; i < N; i++) a[i] = 0;

        for (auto i : s) {
            a[i - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] != 0) {
                if (a[i] % 2 == 1) res += 1;
                else res += 2;
            }
        }
    }
};