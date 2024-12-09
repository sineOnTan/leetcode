#include <bits/stdc++.h>
using namespace std;

// Determines which numbers are special and stores them in a set.
// Then by finding whether there is a number that breaks the rule within the range.
// Some edge cases needed to be ironed out.

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> sln;

        set<int> not_special;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                not_special.insert(i);
            }
        }

        for (auto i : queries) {
            if (i[0] == i[1] or not_special.lower_bound(i[0]) == not_special.end() or *not_special.lower_bound(i[0]) >= i[1]) sln.push_back(true);
            else sln.push_back(false);
        }
        return sln;
    }
};