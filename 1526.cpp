#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int pred = 0;
        int res = 0;

        for (auto i : target) {
            res += max(0, i - pred);
            pred = i;
        }

        return res;
    }
};