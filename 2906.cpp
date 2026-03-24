#include <bits/stdc++.h>
using namespace std;
#define space << " "


const int MOD = 12345;


class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> res;

        vector<vector<int>> pre;
        vector<vector<int>> suff;

        for (int i = 0; i < grid.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < grid[0].size(); j++) {
                temp.push_back(0);
            }
            pre.push_back(temp);
        }

        for (int i = 0; i < grid.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < grid[0].size(); j++) {
                temp.push_back(1);
            }
            suff.push_back(temp);
        }

        for (int i = 0; i < grid.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < grid[0].size(); j++) {
                temp.push_back(0);
            }
            res.push_back(temp);
        }

        int run = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                pre[i][j] = run;

                run *= grid[i][j] % MOD;
                run %= MOD;
            }
        }

        run = 1;

        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                suff[i][j] = run;

                run *= grid[i][j] % MOD;
                run %= MOD;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res[i][j] = pre[i][j] * suff[i][j];
                res[i][j] %= MOD;
            }
        }

        return res;
    }
};