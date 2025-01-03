#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<int> pre_sums;
        long long pre = 0;
        long long sum = 0;
        int res = 0;
        for (auto i : nums) {
            sum += i;
        }
        for (auto i : nums) {
            pre += i;
            if (pre >= (sum - pre)) res++;
        }
        if (pre >= (sum - pre)) res--;
        return res;
    }
};