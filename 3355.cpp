#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = 1e5 + 5;
        int increment[N];
        int decrement[N];

        for (int i = 0; i < N; i++) {
            increment[i] = 0;
            decrement[i] = 0;
        }

        for (auto i : queries) {
            increment[i[0]]++;
            decrement[i[1]]++;
        }

        int change = 0;
        for (int i = 0; i < nums.size(); i++) {
            change += increment[i];
            cout << nums[i] << " " << change << " " << i << endl;;
            if (nums[i] - change > 0) return false;
            change -= decrement[i];
        }
        return true;
    }
};