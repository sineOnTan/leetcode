#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        const int N = 30;
        int a[N];
        for (int i = 0; i < N; i++) a[i] = 0;
        for (auto i : s) a[i - 'a']++;
        int odds = 0;

        for (int i = 0; i < N; i++) if (a[i] % 2 == 1) odds++;
        return odds <= k and s.size() > k;
    }
};