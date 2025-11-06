#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int p[N];

int parent(int i) {
    if (p[i] == i) return i;
    cout << i << " " << p[i] << endl;
    p[i] = parent(p[i]);
    return p[i];
}

void join(int i, int j) {
    i = parent(i);
    j = parent(j);

    p[i] = p[j];
}

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        for (int i = 0; i <= c; i++) {
            p[i] = i;
        }

        for (auto i : connections) {
            join(i[0], i[1]);
        }

        map<int,set<int>> m;

        for (int i = 0; i <= c; i++) {
            m[parent(i)].insert(i);
        }
        vector<int> res;
        for (auto i : queries) {
            if (i[0] == 1) {
                if (m[parent(i[1])].size() == 0) res.push_back(-1);
                else if (m[parent(i[1])].find(i[1]) == m[parent(i[1])].end()) res.push_back(*m[parent(i[1])].begin());
                else res.push_back(i[1]);
            } else if (i[0] == 2) {
                m[parent(i[1])].erase(i[1]);
            }
        }
        return res;
    }
};