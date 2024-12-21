#include <bits/stdc++.h>

using namespace std;

const long long N = 30010;

class Solution {
public:
    vector<long long> graph_edges[N];
    long long res = 0;
    vector<int> vals;
    long long div;

    long long dfs(long long n, long long from = -1) {
        long long temp = vals[n];
        for (auto i : graph_edges[n]) {
            if (i != from) {
                temp += dfs(i, n);
            }
        }
        if (temp % div == 0) res++;
        return temp % div;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vals = values;
        div = k;

        for (auto &i : edges) {
            graph_edges[i[0]].push_back(i[1]);
            graph_edges[i[1]].push_back(i[0]);
        }

        dfs(0);
        return res;
    }
};