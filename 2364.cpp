#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> m;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += m[nums[i] - i];
            m[nums[i] - i]++;
        }
        return (nums.size() * (nums.size() - 1) / 2) - res;
    }
};