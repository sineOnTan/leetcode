#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for (int i = 0; i < k; i++) {
            int lowest = INT_MAX;
            int index = 0;
            int index_lowest = 0;

            for (auto i : nums) {
                if (i < lowest) {
                    lowest = i;
                    index_lowest = index;
                }
                index++;
            }
            nums[index_lowest] *= multiplier;
        }
        return nums;
    }
};