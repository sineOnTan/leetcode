#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << " " << i + 1 << endl;
            if (nums[i] != i + 1) return false;
        }

        return nums[nums.size() - 1] == nums.size() - 1;
    }
};