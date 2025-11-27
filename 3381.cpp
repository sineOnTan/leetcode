#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long cur = 0;
        queue<long long> q;
        for (int i = 0; i < k; i++) {
            cur += nums[i];
            if (i == k - 1) q.push(cur);
            else q.push(0);
        }

        long long res = cur;

        for (int i = k; i < nums.size(); i++) {
            cur += nums[i];
            cur -= nums[i - k];

            long long best = max(q.front() + cur, cur);
            res = max(res, best);
            q.pop();
            q.push(best);
        }
        return res;
    }
};