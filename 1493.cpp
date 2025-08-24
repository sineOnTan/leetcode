#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> preds = nums;
        vector<int> succs = nums;

        for (int i = 0; i < nums.size(); i++) {
            preds[i] = 0;
            succs[i] = 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == 0) preds[i] = 0;
            else preds[i] = preds[i - 1] + 1;
        }

        reverse(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == 0) succs[i] = 0;
            else succs[i] = succs[i - 1] + 1;
        }

        reverse(succs.begin(), succs.end());

        int res = 0;
        res = max(res, succs[0]);
        res = max(res, preds[nums.size() - 1]);

        for (int i = 1; i < nums.size() - 1; i++) {
            res = max(res, succs[i] + preds[i]);
        }
        return res;
    }
};