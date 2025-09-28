#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 2; i < nums.size(); i++) {
            cout << nums[i] << endl;
            if (nums[i - 2] + nums[i - 1] > nums[i]) res = max(res, nums[i - 2] + nums[i - 1] + nums[i]);
        }
        return res;
    }
};