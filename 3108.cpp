#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            const int N = 1e5 + 5;
            bool seen[N];
            int parent[N];
            int cost[N];

            vector<pair<int,int>> vec_edge[N];

            for (auto i : edges) {
                vec_edge[i[0]].emplace_back(i[1],i[2]);
                vec_edge[i[1]].emplace_back(i[0],i[2]);
            }

            for (int i = 0; i < n; i++) {seen[i] = false; parent[i] = i;}
            
            for (int i = 0; i < n; i++) {
                if (!seen[i]) {
                    set<int> cur_nodes;
                    queue<int> q;
                    int res = INT_MAX;
                    q.push(i);
                    cur_nodes.insert(i);
                    while (q.size() != 0) {
                        int cur = q.front();
                        q.pop();
                        for (auto j : vec_edge[cur]) {
                            res &= j.second;

                            if (seen[j.first]) continue;
                            seen[j.first] = true;
                            q.push(j.first);
                            cur_nodes.insert(j.first);
                        }
                    }
                    for (auto j : cur_nodes) {
                        parent[j] = i;
                        cost[j] = res;
                    }
                }
            }
            vector<int> ret;
            for (auto i : query) {
                if (parent[i[0]] != parent[i[1]]) ret.push_back(-1);
                else ret.push_back(cost[i[0]]);
            }
            return ret;
        }
    };