#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
long long a[N][N];
const int mod = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                a[i][j] = 0;

        a[1][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < forget - 1; j++) {
                if (j < delay - 1) a[i + 1][j + 1] = a[i][j];
                else {
                    a[i + 1][j + 1] = a[i][j];
                    a[i + 1][j + 1] %= mod;
                    a[i + 1][0] += a[i][j];
                    a[i + 1][0] %= mod;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < forget; i++) {res += a[n][i]; res %= mod;}
        return res;
    }
};