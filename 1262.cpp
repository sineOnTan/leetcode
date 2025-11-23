#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;

        vector<int> ones;
        vector<int> twos;
        for (auto i : nums) {
            if (i % 3 == 1) ones.push_back(i);
            else if (i % 3 == 2) twos.push_back(i);
        }
        sort(ones.begin(), ones.end());
        sort(twos.begin(), twos.end());

        int res = 0;
        if (sum % 3 == 1) return sum - ones[0];
        else if (sum % 3 == 2) {
            if (ones.size() >= 2) res = max(res, sum - ones[0] - ones[1]);
            if (twos.size() >= 1) res = max(res, sum - twos[0]);
            return res;
        }
        return res;
    }
};