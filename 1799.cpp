#include <bits/stdc++.h>
using namespace std;

const int N = 50000;
int vec[N];

class Solution {
public:
    int maxScore(vector<int>& nums) {
        for (int i = 0; i < 1 << (nums.size() + 1); i++) vec[i] = 0;
        vector<int> bases;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int pos = (1 << i) | (1 << j);
                bases.push_back(pos);
                vec[pos] = max(vec[pos], gcd(nums[i], nums[j]));
                res = max(res, vec[pos]);
            }
        }

        for (int i = 0; i < (1 << nums.size()); i++) {
            if (__builtin_popcount(i) % 2 != 0) continue;

            int nums = __builtin_popcount(i);
            for (auto j : bases) {
                if ((i & j) == 0) {
                    vec[i | j] = max(vec[i | j], (vec[j] * (((nums) / 2) + 1)) + vec[i]);
                    res = max(res, vec[i | j]);
                }
            }
        }

        return res;
    }
};