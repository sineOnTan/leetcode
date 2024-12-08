#include <bits/stdc++.h>

using namespace std;
#define int long long

#define YES {cout << "YES" << endl;}
#define NO {cout << "NO" << endl;}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>> endTimes;
        priority_queue<pair<int,int>> startTimes;

        for (auto i : events) {
            endTimes.emplace(i[2],i[3]);
        }
    }
};