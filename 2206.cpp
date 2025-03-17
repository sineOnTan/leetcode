#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            bool a[505] = {false};
            for (auto i : nums) a[i] = !a[i];
            for (int i = 0; i < 505; i++) if (a[i] == true) return false;
            return true;
        }
    };