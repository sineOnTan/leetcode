#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mod = grid[0][0] % x;
        int count = 0;
        map<int,int> m;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] -= mod;
                if (grid[i][j] % x != 0) return -1;
                grid[i][j] /= x;
                m[grid[i][j]]++;
                
            }
        }

        int res = INT_MAX;

        int next_nums = 0;
        int pred_nums = 0;
        int cur = 0;

        for (auto i : m) {
            next_nums += i.second;
            cur += (i.first - (*(m.begin())).first) * i.second;
        }

        int pred = (*(m.begin())).first;

        for (auto i : m) {
            cur -= next_nums * (i.first - pred);
            cur += pred_nums * (i.first - pred);

            next_nums -= i.second;
            pred_nums += i.second;
            
            res = min(res, cur);
            pred = i.first;
        }

        return res;
    }
};