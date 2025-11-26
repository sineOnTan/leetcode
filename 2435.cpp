#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int div) {
        const int m=grid.size(), n=grid[0].size();
        int a[m][n][div];

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                for (int k = 0; k < div; k++)
                    a[i][j][k] = 0;
                    
        a[0][0][grid[0][0] % div] = 1;
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                for (int k = 0; k < div; k++) {
                    int cur = grid[i][j];
                    if (i != 0) a[i][j][k] += a[i - 1][j][(k - cur + (100 * div)) % div];
                    if (j != 0) a[i][j][k] += a[i][j - 1][(k - cur + (100 * div)) % div];
                    a[i][j][k] %= mod;
                }

        return a[grid.size() - 1][grid[0].size() - 1][0];
    }
};