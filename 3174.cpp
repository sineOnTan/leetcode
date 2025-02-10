#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            string res;
            for (auto i : s) {
                if (i <= '9' and i >= '0') res.pop_back();
                else res.push_back(i);
            }
        }
    };