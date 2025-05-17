#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[4];
        for (auto i : nums) a[i]++;

        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (a[cur] <= 0) cur++;
            nums[i] = a[cur];
            a[cur]--;
        }
    }
};