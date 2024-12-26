using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> curs;
        vector<int> next;

        curs.push_back(0);
        for (auto i : nums) {
            for (auto j : curs) {
                next.push_back(j + i);
                next.push_back(j - i);
            }
            curs.clear();
            swap(next, curs);
        }

        int res = 0;
        for (auto i : curs) if (target == i) res++;
        return res;
    }
};