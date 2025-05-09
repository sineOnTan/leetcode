#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

class Solution {
    public:
        int countBalancedPermutations(string num) {
            int a[100][1000];

            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 1000; j++) {
                    a[i][j] = 0;
                }
            }

            a[0][0] = 1;
            int sum = 0;

            for (auto n : num) {
                sum += n - '0';

                for (int i = 85; i >= 0; i--) {
                    for (int j = 990; j >= 0; j--) {
                        a[i + 1][j + (int)(n - '0')] += a[i][j];
                        a[i + 1][j + (int)(n - '0')] %= MOD;
                    }
                }
            }
            if (sum % 2 != 0) return 0;

            int res = a[num.size()/2][sum/2];

            for (int i = 0; i < num.size()/2; i++) {
                res *= i;
                res %= MOD;
            }

            if (num.size() % 2 == 1) {
                res *= (num.size() / 2) + 1;
                res %= MOD;
            }
            
            return a[num.size()/2][sum/2];
        }
    };