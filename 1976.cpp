#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int N = n + 5;
            int a[N];
            int ways[N];


            for (int i = 0; i < N; i++) {a[i] = INT_MAX; ways[i] = 0;}

            map<int,vector<pair<int,int>>> m;
            for (auto i : roads) {
                m[i[0]].emplace_back(i[1], i[2]);
                m[i[1]].emplace_back(i[0], i[2]);
            }

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.emplace(0, 0);
        }
    };