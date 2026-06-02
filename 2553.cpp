#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        vector<int> temp;
        for (auto i : nums) {
            while (i != 0) {
                temp.push_back(i % 10);
                i /= 10;
            }
            reverse(temp.begin(), temp.end());
            for (auto j : temp) res.push_back(j);
            temp.clear();
        }
        return res;
    }
};