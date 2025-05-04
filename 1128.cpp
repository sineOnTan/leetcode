#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int res = 0;
            map<pair<int,int>, int> m;
            for (auto i : dominoes) {
                if (i[0] > i[1]) swap(i[0], i[1]);

                res += m[make_pair(i[0], i[1])];
                m[make_pair(i[0], i[1])]++;
            }
            return res;
        }
    };