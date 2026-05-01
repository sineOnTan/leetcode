#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        for (int i = 0; i < source.size(); i++) {
            parent.push_back(i);
        }

        for (auto i : allowedSwaps) {
            join(i[0], i[1]);
        }
        
        for (int i = 0; i < source.size(); i++) {
            parent[i] = root(i);
        }
        map<int, multiset<int>> m;

        for (int i = 0; i < source.size(); i++) {
            m[parent[i]].insert(source[i]);
        }

        for (int i = 0; i < target.size(); i++) {
            if (m[parent[i]].find(target[i]) != m[parent[i]].end()) m[parent[i]].erase(m[parent[i]].find(target[i]));
        }

        int res = 0;

        for (auto i : m) {
            res += i.second.size();
        }

        return res;
    }

    int root(int x) {
        if (x == parent[x]) return x;
        else {
            parent[x] = root(parent[x]);
            return parent[x];
        }
    }

    void join(int x, int y) {
        x = root(x);
        y = root(y);
        // if (x == y) return;
        parent[y] = x;
    }
};