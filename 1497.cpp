#include <bits/stdc++.h>

const int N = 100100;
int a[N];

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for (int i = 0; i< N; i++) a[i] = 0;
        for (auto i : arr) a[(i % k + (k * (i < 0))) % k]++;
        for (int i = 1; i < k; i++) if (a[i] != a[k - i]) return false;
        if (a[0] % 2 != 0) return false;
        return true;
    }
};