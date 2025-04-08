#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for (auto i : nums) sum += i;
            int sum_2 = 0;
            for (auto i : nums) {
                sum_2 += i;
                if (sum / 2 == sum_2) return true;
            }
            return false;
        }
    };