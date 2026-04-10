#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        
        int res = INT_MAX;
        for (auto i : m) {
            for (int j = 1; j < i.second.size() - 1; j++) {
                res = min(res, (i.second[j + 1] - i.second[j - 1]) * 2);
            }
        }
        if (res == INT_MAX) return -1;
        else return res;
    }
};