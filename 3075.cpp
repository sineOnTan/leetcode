#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        long long res = 0;

        for (int i = 0; i < k; i++) {
            if (happiness[i] - i <= 0) return res;
            res += happiness[i] - i;
        }
        return res;
    }
};