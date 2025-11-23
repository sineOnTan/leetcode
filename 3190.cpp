#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (auto i : nums) {
            if (i % 3 != 0) res++;
        }
        return res;
    }
};