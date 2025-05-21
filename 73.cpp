#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> v1;
        set<int> v2;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    v1.insert(i);
                    v2.insert(j);
                }
            }
        }

        for (auto i : v1) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }

        for (auto j : v2) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
};