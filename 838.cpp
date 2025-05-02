#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long ri[N];
long long le[N];

class Solution {
    public:
        string pushDominoes(string dominoes) {
            if (dominoes[0] == 'R') ri[0] = 0;
            else ri[0] = (long long)INT_MAX;

            for (int i = 1; i < dominoes.size(); i++) {
                if (dominoes[i] == 'L') ri[i] = (long long)INT_MAX;
                else if (dominoes[i] == 'R') ri[i] = 0;
                else ri[i] = min(ri[i - 1] + 1, (long long)INT_MAX);
            }

            if (dominoes[dominoes.size() - 1] == 'L') le[dominoes.size() - 1] = 0;
            else le[dominoes.size() - 1] = (long long)INT_MAX;

            for (int i = dominoes.size() - 2; i >= 0; i--) {
                if (dominoes[i] == 'R') le[i] = (long long)INT_MAX;
                else if (dominoes[i] == 'L') le[i] = 0;
                else le[i] = min(le[i + 1] + 1, (long long)INT_MAX);
            }
            string res;

            for (int i = 0; i < dominoes.size(); i++) {
                if (le[i] < ri[i]) res.push_back('L');
                else if (le[i] > ri[i]) res.push_back('R');
                else res.push_back('.');
            }
            return res;
        }
    };