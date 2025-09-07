#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int smth = 0;
        for (int i = 1; i < n; i++) {
            smth += i;
            res.push_back(i);
        }
        res.push_back(-smth);
        return res;
    }
};