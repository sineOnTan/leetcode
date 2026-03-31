#include <bits/stdc++.h>
using namespace std;
#define space << " "


class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for (auto i : grid) {
            for (auto j : i) {
                sum += j;
            }
        }

        long long temp_sum = 0;
        for (auto i : grid) {
            for (auto j : i) {
                temp_sum += j;
            }

            if (temp_sum * 2 == sum) return true;
        }

        temp_sum = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                temp_sum += grid[j][i];
            }
            if (temp_sum * 2 == sum) return true;
        }


        return false;
    }
};