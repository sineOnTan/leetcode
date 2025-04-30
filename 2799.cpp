#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            map<int, int> m;
            for (auto i : nums) m[i]++;
            int res = 1;
            for (auto i : m) res *= i.second;
            return res;
        }
    };