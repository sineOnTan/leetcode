#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) cur += nums[i];
            else {
                res = max(cur, res);
                cur = nums[i];
            }
        }
        return max(cur, res);
    }
};