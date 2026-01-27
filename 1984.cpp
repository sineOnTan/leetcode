#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = INT_MAX;

        for (int i = 0; i + k - 1 < nums.size(); i++) {
            res = min(nums[i + k - 1] - nums[i], res);
        }
        return res;
    }
};