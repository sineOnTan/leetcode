#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int cur = 0;
            int mx = 0;
            int mn = 0;
            for (auto i : differences) {
                cur += i;
                if (cur >= 1e6 or cur <= -1e6) return 0;
                mx = max(cur, mx);
                mn = min(cur, mn);
            }

            int diff = upper - lower + 1;

            return max(0, diff - (mx - mn));
        }
    };