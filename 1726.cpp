#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        multiset<int> s;
        for (int i = 0; i < nums.size(); i++) 
            for (int j = i + 1; j < nums.size(); j++) {
                s.insert(nums[i] * nums[j]);
            }
        
        while (s.size() != 0){
            int t = s.count(*s.begin());
            res += ((t - 1) * t) / 2;
            s.erase(*s.begin());
        }
        return res * 8;
    }
};