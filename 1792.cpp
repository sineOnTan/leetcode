#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;

        for (auto i : classes) pq.emplace( 
            ((double)(i[0] + 1) / (double)(i[1] + 1)) - ((double)i[0] / (double)i[1]),
            make_pair(i[0], i[1])
        );

        while (extraStudents--) {
            auto cur = pq.top().second;
            vector<int> i;
            i.push_back(cur.first + 1);
            i.push_back(cur.second + 1);
            pq.pop();


            pq.emplace(
                ((double)(i[0] + 1) / (double)(i[1] + 1)) - ((double)i[0] / (double)i[1]),
                make_pair(i[0], i[1])
            );
        }
        double res = 0;
        double size = pq.size();
        while(pq.size() != 0) {
            res += (double)pq.top().second.first / (double)pq.top().second.second;
            pq.pop();
        }
        return res / size;
    }
};