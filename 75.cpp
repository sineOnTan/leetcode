#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[4];
        for (auto i : nums) a[i]++;

        for (int i = 0; i < 4; i++) cout << a[i] << endl;

        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (a[cur] <= 0) cur++;
            nums[i] = cur;
            a[cur]--;
        }
    }
};