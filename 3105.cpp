#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool increasing = true;
        int res = 0;
        int cur_streak = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {if(increasing) cur_streak++; else {res = max(cur_streak, res); cur_streak = 2;} increasing = true;}
            else if (nums[i] < nums[i - 1]) {if(!increasing) cur_streak++; else {res = max(cur_streak, res); cur_streak = 2;} increasing = false;}
            else {res = max(res, cur_streak); cur_streak = 1;}
        }
        res = max(res, cur_streak);
        return res;
    }
};