#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    if (i == j or i == k or j == k) continue;

                    int temp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (temp / 100 == 0) continue;
                    else if (temp % 2 == 0) res.insert(temp);
                }
            }
        }
        vector<int> r;
        for (auto i : res) r.push_back(i);
        return r;
    }
};