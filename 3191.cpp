#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int res = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 1) {
                    nums[i] = !nums[i];
                    nums[i + 1] = !nums[i + 1];
                    nums[i + 2] = !nums[i + 2];
                    res++;
                }
            }
            int end = nums.size() - 1;
            if (nums[end] != 1 and nums[end - 1] != 1 and nums[end - 2] != 1) return -1;
            return res;
        }
    };