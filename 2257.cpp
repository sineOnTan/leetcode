#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int a[m][n];
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                a[i][j] = 0;

        int unguarded = m * n;

        for (auto i : walls) {a[i[0]][i[1]] = 1; unguarded--;}
        cout << unguarded << endl;

        for (auto i : guards) {
            if (a[i[0]][i[1]] == 0) unguarded--;
            a[i[0]][i[1]] = 1;
        }


        for (auto i : guards) {
            if (a[i[0]][i[1]] == 0) unguarded--;
            a[i[0]][i[1]] = 1;

            for (int j = i[0] - 1; j >= 0; j--) {
                if (a[j][i[1]] == 0) unguarded--;
                else if (a[j][i[1]] == 1) break;
                a[j][i[1]] = 2;
            }

            for (int j = i[0] + 1; j < m; j++) {
                if (a[j][i[1]] == 0) unguarded--;
                else if (a[j][i[1]] == 1) break;
                a[j][i[1]] = 2;
            }

            for (int j = i[1] - 1; j >= 0; j--) {
                if (a[i[0]][j] == 0) unguarded--;
                else if (a[i[0]][j] == 1) break;
                a[i[0]][j] = 2;
            }
            for (int j = i[1] + 1; j < n; j++) {
                if (a[i[0]][j] == 0) unguarded--;
                else if (a[i[0]][j] == 1) break;
                a[i[0]][j] = 2;
            }
        }

        return unguarded;
    }
};