#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                for (int j = 1; j <= k and i + j < nums.size(); j++) {
                    if (nums[i + j] == 1) return false;
                }
                i = i + k;
            }
        }
        return true;
    }
};