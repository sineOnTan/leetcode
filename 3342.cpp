#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            vector<vector<int>> minTime = moveTime;

            for (int i = 0; i < minTime.size(); i++) {
                for (int j = 0; j < minTime[0].size(); j++) {
                    minTime[i][j] = INT_MAX;
                }
            }

            priority_queue<pair<int, pair<int,int>>, std::vector<pair<int, pair<int,int>>>, std::greater<pair<int, pair<int,int>>>> pq;
            pq.emplace(0, make_pair(0,0));

            while (pq.size() != 0) {
                auto cur = pq.top();
                pq.pop();
                if (minTime[cur.second.first][cur.second.second] <= cur.first) continue;

                minTime[cur.second.first][cur.second.second] = cur.first;

                int time_inc = 1;
                if (((cur.second.first + cur.second.second) % 2) != 0) time_inc++;

                if (cur.second.first >= 1) pq.emplace(max(moveTime[cur.second.first - 1][cur.second.second] + time_inc, cur.first + time_inc), make_pair(cur.second.first - 1, cur.second.second));
                if (cur.second.second >= 1) pq.emplace(max(moveTime[cur.second.first][cur.second.second - 1] + time_inc, cur.first + time_inc), make_pair(cur.second.first, cur.second.second - 1));
                if (cur.second.first + 1 < moveTime.size()) pq.emplace(max(moveTime[cur.second.first + 1][cur.second.second] + time_inc, cur.first + time_inc), make_pair(cur.second.first + 1, cur.second.second));
                if (cur.second.second + 1 < moveTime[0].size()) pq.emplace(max(moveTime[cur.second.first][cur.second.second + 1] + time_inc, cur.first + time_inc), make_pair(cur.second.first, cur.second.second + 1));
            }

            return minTime[moveTime.size() - 1][moveTime[0].size() - 1];
        }
    };