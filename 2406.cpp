#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<int> endTimes;
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a,
            const vector<int>& b) {
            return a[1] < b[1];
        });

        for (auto i : intervals) {
            if(endTimes.lower_bound(i[0]) != endTimes.begin()) endTimes.erase(--endTimes.lower_bound(i[0]));

            endTimes.insert(i[1]);

        }
        return endTimes.size();
    }
};