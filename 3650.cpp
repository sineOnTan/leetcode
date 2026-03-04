#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> adj_list;
    vector<int> min_cost;

    int minCost(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            min_cost.push_back(INT_MAX);
            adj_list.emplace_back();
        }

        for (auto i : edges) {
            adj_list[i[0]].emplace_back(i[1], i[2]);
            adj_list[i[1]].emplace_back(i[0], i[2] * 2);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.emplace(0,0);

        while (pq.size() != 0) {
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist >= min_cost[node]) continue;
            min_cost[node] = dist;

            for (auto i : adj_list[node]) {
                pq.emplace(i.second + dist, i.first);
            }
        }
        if (min_cost[n - 1] == INT_MAX) return -1;
        return min_cost[n - 1];
    }
};