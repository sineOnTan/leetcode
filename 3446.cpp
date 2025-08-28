#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            vector<int> vec;
            for (int j = 0; j + i < grid.size(); j++) {
                vec.push_back(grid[j + i][j]);
            }
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());
            for (int j = 0; j + i < grid.size(); j++) {
                grid[j + i][j] = vec[j];
            }
        }

        for (int i = 1; i < grid.size(); i++) {
            vector<int> vec;
            for (int j = 0; j + i < grid.size(); j++) {
                vec.push_back(grid[j][j + i]);
            }
            sort(vec.begin(), vec.end());
            for (int j = 0; j + i < grid.size(); j++) {
                grid[j][j + i] = vec[j];
            }
        }
        return grid;
    }
};