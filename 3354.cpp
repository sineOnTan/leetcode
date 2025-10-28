#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> pred;
        vector<int> suff;

        int sum = 0;

        for (auto i : nums) {
            pred.push_back(sum);
            sum += i;
        }

        reverse(nums.begin(), nums.end());
        sum = 0;
        for (auto i : nums) {
            suff.push_back(sum);
            sum += i;
        }

        reverse(nums.begin(), nums.end());
        reverse(suff.begin(), suff.end());
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 and pred[i] == suff[i]) res += 2;
            else if (nums[i] == 0 and pred[i] == suff[i] + 1) res++;
            else if (nums[i] == 0 and pred[i] == suff[i] - 1) res++;
        }
        return res;
    }
};