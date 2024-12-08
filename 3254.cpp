#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int pred = -1;
        int length = 1;
        vector<int> res;
        int count = 0;
        for (auto i : nums) {
            count++;
            if (i == pred + 1) length++;
            else length = 1;
            pred = i;
            if (length >= k or k == 1) res.push_back(pred);
            else if (count >= k) res.push_back(-1);
        }
        return res;
    }
};