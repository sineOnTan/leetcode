#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int a[N][N];

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int i = 0; i < triangle.size(); i++) a[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                a[i][j] = min(a[i + 1][j], a[i + 1][j + 1]);
                a[i][j] += triangle[i][j];
            }   
        }
        return a[0][0];
    }
};