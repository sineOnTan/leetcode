#include <bits/stdc++.h>
using namespace std;
#define space << " "

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> hori;
        vector<int> vert;
        int res = 0;

        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            hori.push_back(count);
        }

        for (int j = 0; j < mat[0].size(); j++) {
            int count = 0;
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][j] == 1) count++;
            }
            vert.push_back(count);
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (hori[i] == 1 and vert[j] == 1 and mat[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};