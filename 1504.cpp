#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 1; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) mat[i][j] = mat[i][j - 1] + 1;
            }
        }
    }
};