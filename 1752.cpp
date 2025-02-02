#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int jumped = false;
        int num = 0;
        int pred_max = 0;
        for(int i : nums) {
            if (i >= num) num = i;
            else if (jumped) return false;
            else {jumped = true; pred_max = num; num = 0; cout << "jumped " << pred_max << endl;}
        }
        cout << *nums.rbegin() << " " << pred_max;
        return !(*nums.rbegin() > pred_max and pred_max != 0);
    }
};