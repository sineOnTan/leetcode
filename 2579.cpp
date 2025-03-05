#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long coloredCells(int n) {
            long long res = 1;
            for (int i = 2; i <= n; i++) {
                res += 2 + 2 + (i - 2) * 4;
            }
            return res;
        }
    };