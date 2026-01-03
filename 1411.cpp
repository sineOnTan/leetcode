#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

long long arr[N][27];
const int mod = 1e9 + 7;

class Solution {
public:
    int numOfWays(int n) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 27; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < 27; i++) {
            if (i % 3 == (i / 3) % 3 or (i / 3) % 3 == (i / 9) % 3) arr[0][i] = 0;
            else arr[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 27; j++) {
                if (j % 3 == (j / 3) % 3 or (j / 3) % 3 == (j / 9) % 3) {arr[i][j] = 0; continue;}
                for (int k = 0; k < 27; k++) {
                    if (j % 3 == k % 3 or (j / 3) % 3 == (k / 3) % 3 or (j / 9) % 3 == (k / 9) % 3) continue;
                    else arr[i][j] += arr[i - 1][k];
                    arr[i][j] %= mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 27; i++) {
            res += arr[n - 1][i];
            res %= mod;
        }

        return res;
    }
};