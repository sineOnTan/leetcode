#include <bits/stdc++.h>
using namespace std;
#define space << " "

const int N = 20;
pair<long long,long long> counts[N][N];
const int MOD = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {        
        counts[0][0].first = grid[0][0];
        counts[0][0].second = grid[0][0];

        for (int i = 1; i < grid.size(); i++) {
            counts[i][0].first = counts[i - 1][0].first * grid[i][0];
            counts[i][0].second = counts[i - 1][0].second * grid[i][0];
        }

        
        for (int j = 1; j < grid[0].size(); j++) {
            counts[0][j].first = counts[0][j - 1].first * grid[0][j];
            counts[0][j].second = counts[0][j - 1].second * grid[0][j];
        }

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                counts[i][j].first = computer_quad_max(counts[i - 1][j].first, counts[i - 1][j].second, counts[i][j - 1].first, counts[i][j - 1].second, grid[i][j]);
                counts[i][j].second = computer_quad_min(counts[i - 1][j].first, counts[i - 1][j].second, counts[i][j - 1].first, counts[i][j - 1].second, grid[i][j]);;
            }
        }

        if (counts[grid.size() - 1][grid[0].size() - 1].first < 0) return -1;
        return counts[grid.size() - 1][grid[0].size() - 1].first % MOD;
        
    }

    long long computer_quad_max(long long q1, long long q2, long long q3, long long q4, long long mult) {
        return max(max(q1 * mult, q2 * mult), max(q3 * mult, q4 * mult));
    }

    long long computer_quad_min(long long q1, long long q2, long long q3, long long q4, long long mult) {
        return min(min(q1 * mult, q2 * mult), min(q3 * mult, q4 * mult));
    }
};