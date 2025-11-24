#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;

        int cur = 0;
        for (auto i : nums) {
            cur *= 2;
            cur %= 5;
            if (i) cur += 1;
            if (cur % 5 == 0) res.push_back(1);
            else res.push_back(0);
        }

        return res;
    }
};