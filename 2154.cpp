#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;
        for (auto i : nums) s.insert(i);
        while(s.contains(original)) original *= 2;
        
        return original;
    }
};