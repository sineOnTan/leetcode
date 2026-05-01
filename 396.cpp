#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur = 0;
        int res = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += i * nums[i];
            sum += nums[i];
        }

        res = max(cur, res);

        for (int i = 1; i < nums.size(); i++) {
            cur -= sum;
            cur += (nums.size()) * nums[i - 1];
            res = max(cur, res);
        }

        return res;
    }
};