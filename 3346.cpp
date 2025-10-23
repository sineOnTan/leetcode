#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int cur = 0;
        int point = 0;

        int best = 0;

        while (cur < nums.size()) {


            while (point != nums.size() - 1 and (nums[cur] + 2 * k) >= nums[point]) {
                point++;
            }
            cout << point - cur;
            best = max(best, point - cur);
            cur++;
        }
        return best;
    }
};