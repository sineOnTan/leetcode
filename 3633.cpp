#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int best = INT_MAX;
        int start_best = INT_MAX;

        for (int i = 0; i < waterDuration.size(); i++) {
            start_best = min(start_best, waterDuration[i] + waterStartTime[i]);
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            if (landStartTime[i] <= start_best) best = min(best, start_best + landDuration[i]);
            else best = min(best, landDuration[i] + landStartTime[i]);
        }

        start_best = INT_MAX;

        for (int i = 0; i < landDuration.size(); i++) {
            start_best = min(start_best, landDuration[i] + landStartTime[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            if (waterStartTime[i] <= start_best) best = min(best, start_best + waterDuration[i]);
            else best = min(best, waterDuration[i] + waterStartTime[i]);
        }

        return best;

    }
};