using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < values.size(); i++) pq.emplace((values[i] - i), i);

        int max_v = 0;

        for(int i = 0; i < values.size() - 1; i++) {
            while (pq.top().second <= i) pq.pop();
            max_v = max(max_v, values[i] + i + pq.top().first - pq.top().second);
        }

        return max_v
    }
};