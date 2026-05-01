#include <bits/stdc++.h>
using namespace std;

const int N = 202;
const int M = 500;
int a[N][N][M];

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        if (k >= 500) k = 410;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                for (int l = 0; l < M; l++) a[i][j][l] = -1;
            }
        }

        for (int l = 0; l <= k; l++) a[0][0][l] = 0;

        for (int i = 1; i < grid.size(); i++) {
            for (int l = 0; l <= k; l++) {
                if (grid[i][0] == 0) a[i][0][l] = a[i - 1][0][l];
                else {
                    if (a[i - 1][0][l + 1] == -1) a[i][0][l] = -1;
                    else a[i][0][l] = a[i - 1][0][l + 1] + grid[i][0];
                }
            }
        }

        for (int j = 1; j < grid[0].size(); j++) {
            for (int l = 0; l <= k; l++) {
                if (grid[0][j] == 0) a[0][j][l] = a[0][j - 1][l];
                else {
                    if (a[0][j - 1][l + 1] == -1) a[0][j][l] = -1;
                    else a[0][j][l] = a[0][j - 1][l + 1] + grid[0][j];
                }
            }
        }

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                for (int l = 0; l <= k; l++) {
                    if (grid[i][j] == 0) a[i][j][l] = max(a[i][j - 1][l], a[i - 1][j][l]);
                    else {                        
                        if (max(a[i][j - 1][l + 1], a[i - 1][j][l + 1]) == -1) a[i][j][l] = -1;
                        else a[i][j][l] = max(a[i][j - 1][l + 1], a[i - 1][j][l + 1]) + grid[i][j];
                    }
                }
            }
        }


        int res = -1;

        for (int l = 0; l <= k; l++) {
            res = max(a[grid.size() - 1][grid[0].size() - 1][l], res);
        }

        return res;
    }
};