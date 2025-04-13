#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const long long N = 1e15 + 5;

class Solution {
    public:
        int countGoodNumbers(long long n) {
            long long res = 1;
            map<long long,long long> m;
            m[0] = 1;
            m[1] = 5;
            m[2] = 20;
            long long temp = 400;
            for (long long i = 2; i < N; i *= 2) {
                m[i * 2] = temp;
                temp *= temp;
                temp %= mod;
            }

            while (n > 0) {
                auto point = m.upper_bound(n)--;
                point--;

                res *= (*point).second;
                n -= (*point).first;
                res %= mod;
            }
            return res;
        }
    };