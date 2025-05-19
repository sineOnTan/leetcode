#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string triangleType(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            if (nums[0] + nums[1] <= nums[2]) return "none";
            if (nums[0] == nums[1] and nums[0] == nums[2]) return "equilateral";
            if (nums[0] == nums[1] or nums[0] == nums[2] or nums[1] == nums[2]) return "isosceles";
            return "scalene";
        }
    };