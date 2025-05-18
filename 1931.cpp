#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int colorTheGrid(int m, int n) {

        const int pm = pow(3, m);
        long long a[250][1005];

        vector<int> candidates;

        for (int i = 0; i < 250; i++) {
            for (int j = 0; j < 1005; j++) a[i][j] = 0;
        }

        for (int i = 0; i < pm; i++) {
            bool flag = true;

            if (m != 1) {
                for (int j = 1; j < m; j++) {
                    if (((i / (int)pow(3, j)) % 3) == ((i / (int)pow(3, (j - 1))) % 3)) flag = false;
                }
            }

            if (flag) {a[i][0] = 1; candidates.push_back(i);}
        }

        for (int j = 1; j < n; j++) {
            for (auto i : candidates) {
                int temp = 0;
                for (auto k : candidates) {
                    bool valid = true;
                    for (int j = 0; j < m; j++) {
                        if (((i / (int)pow(3, j)) % 3) == ((k / (int)pow(3, j)) % 3)) valid = false;
                    }
                    if (valid) {
                        temp += a[k][j - 1];
                        temp %= mod;
                    }
                }
                a[i][j] = temp;
            }
        }

        int res = 0;

        for (auto k : candidates) {
            res += a[k][n - 1];
            res %= mod;
        }

        return res;
    }
};