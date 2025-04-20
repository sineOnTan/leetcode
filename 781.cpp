#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            map<int,int> m;
            for (auto i : answers) m[i]++;
            int res = 0;
            for (auto i : m) {
                res += ceil((i.second * 1.0) / (i.first + 1.0)) * (i.first + 1);
            }
            return res;
        }
    };