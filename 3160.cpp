#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        map<int,int> balls;
        int cur = 0;
        multiset<int> colors;
        for (auto i : queries) {balls[i[0]] = 0; colors.insert(0);}
        colors.insert(0);

        for (auto i : queries) {
            colors.erase(colors.find(balls[i[0]]));
            if (colors.find(balls[i[0]]) == colors.end()) cur--;

            if (colors.find(i[1]) == colors.end()) cur++;
            colors.insert(i[1]);
            balls[i[0]] = i[1];
            res.push_back(cur);
        }
        return res;
    }
};