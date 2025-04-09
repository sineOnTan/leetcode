#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            for (auto i : nums) if (i < k) return false;
            set<int> s;
            for (auto i : nums) if (i > k) s.insert(i);
            return s.size();
        }
    };