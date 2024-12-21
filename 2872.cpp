#include <bits/stdc++.h>

using namespace std;

const long long N = 30010;


class Solution {
public:
    vector<long long> graph_edges[N];
    long long res = 0;
    vector<int> vals;
    vector<int> children[N];
    long long div;

    void dfs(long long n, long long from = -1) {
        for (auto i : graph_edges[n]) {
            if (i != from) {
                children[n].push_back(i);
                dfs(i, n);
            }
        }
    }

    long long get_subtree_size(long long n) {
        long long temp = vals[n];
        for (auto i : children[n]) temp += get_subtree_size(i);
        if (temp % div == 0) res++;
        return temp % div;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vals = values;
        div = k;
        for (long long i = 0; i < N; i++) {
            graph_edges[i].clear();
        }

        for (auto i : edges) {
            graph_edges[i[0]].push_back(i[1]);
            graph_edges[i[1]].push_back(i[0]);
        }

        dfs(0);
        get_subtree_size(0);
        return res;
    }
};