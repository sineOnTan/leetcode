#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int min = -k;

        for (auto i : nums) {
            if (min < i - k) {
                res++;
                min = i - k;
            } else if (min < i + k) {
                res++;
                min++;
            }
        }
        return res;
    }
};