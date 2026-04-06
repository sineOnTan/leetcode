#include <bits/stdc++.h>
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> set_obstacles;
        int direction = 0;
        for (auto i : obstacles) {
            set_obstacles.emplace(i[0], i[1]);
        }

        int res = 0;
        int x = 0;
        int y = 0;

        for (auto i : commands) {
            if (i == -1) direction++;
            else if (i == -2) direction--;
            else {
                direction += 100000;
                direction %= 4;
                for (int j = 0; j < i; j++) {
                    int next_x = x;
                    int next_y = y;
                    if (direction == NORTH) next_y++;
                    else if (direction == EAST) next_x++;
                    else if (direction == SOUTH) next_y--;
                    else if (direction == WEST) next_x--;
                    if (!set_obstacles.contains(make_pair(next_x, next_y))) {
                        x = next_x;
                        y = next_y;
                    }
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};