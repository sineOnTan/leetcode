#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> res;
        for (auto i : nums) res.push_back(-1);

        res[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (res[j] != -1 and abs(nums[i] - nums[j]) <= target)
                    res[i] = max(res[i], res[j] + 1);
            }
            cout << res[i] << endl;
        }

        return res[nums.size() - 1];
    }
};