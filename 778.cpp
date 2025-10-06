#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        for (int i = 0; i <= grid.size() * grid.size() + 1; i++) {
            set<pair<int,int>> seen;
            queue<pair<int,int>> q;

            if (grid[0][0] <= i) {q.emplace(0,0);}

            while(q.size() != 0) {
                auto cur = q.front();
                q.pop();
                if (seen.contains(make_pair(cur.first, cur.second))) continue;
                seen.emplace(cur.first, cur.second);

                if (cur.first != 0) 
                    if (grid[cur.first - 1][cur.second] <= i and !seen.contains(make_pair(cur.first - 1, cur.second)))
                        q.emplace(cur.first - 1, cur.second);
                       
                if (cur.first != grid.size() - 1) 
                    if (grid[cur.first + 1][cur.second] <= i and !seen.contains(make_pair(cur.first + 1, cur.second)))
                        q.emplace(cur.first + 1, cur.second);

                if (cur.second != 0) 
                    if (grid[cur.first][cur.second - 1] <= i and !seen.contains(make_pair(cur.first, cur.second - 1)))
                        q.emplace(cur.first, cur.second - 1);
                       
                if (cur.second != grid.size() - 1) 
                    if (grid[cur.first][cur.second + 1] <= i and !seen.contains(make_pair(cur.first, cur.second + 1)))
                        q.emplace(cur.first, cur.second + 1);
            }

            if (seen.contains(make_pair(grid.size() - 1, grid.size() - 1))) return i;
        }
        return 0;
    }
};