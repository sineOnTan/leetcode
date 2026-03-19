#include <bits/stdc++.h>
using namespace std;
#define space << " "

const int N = 1010;
pair<int,int> counts[N][N];

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int xs = 0;
                int ys = 0;

                if (i != 0) {
                    xs += counts[i - 1][j].first;
                    ys += counts[i - 1][j].second;
                }

                if (j != 0) {
                    xs += counts[i][j - 1].first;
                    ys += counts[i][j - 1].second;
                }

                if (i != 0 and j != 0) {
                    xs -= counts[i - 1][j - 1].first;
                    ys -= counts[i - 1][j - 1].second;
                }

                if (grid[i][j] == 'X') xs++;
                else if (grid[i][j] == 'Y') ys++;

                counts[i][j].first = xs;
                counts[i][j].second = ys;
                
                if (xs != 0 and ys == xs) res++;
            }
        }
        return res;
    }
};