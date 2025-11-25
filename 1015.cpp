#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> seen;
        int cur = 1;
        int res = 1;

        while (!seen.contains(cur)) {
            seen.insert(cur);
            cur %= k;
            if (cur == 0) return res;
            res++;
            cur *= 10;
            cur += 1;
            cout << cur << endl;
        }

        return -1;
    }
};