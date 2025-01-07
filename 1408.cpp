#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (auto i : words) {
            for (auto j : words) {
                if (i == j) continue;
                else if (j.find(i) != string::npos) {res.push_back(i); break;}
            }
        }
        return res;
    }
};