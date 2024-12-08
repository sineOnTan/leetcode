#include <bits/stdc++.h>

using namespace std;

#define YES {cout << "YES" << endl;}
#define NO {cout << "NO" << endl;}
#define space << " "

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        set<pair<int,int>> end_time;
        set<pair<int,int>> start_time;

        for (auto i : events) {
            start_time.emplace(i[0],i[2]);
            end_time.emplace(i[1],i[2]);
        }
        int max_val = 0;
        int max_pred = 0;
        auto start_p = start_time.begin();
        auto end_p = end_time.begin();

        while (start_p != start_time.end()){
            while(end_p != end_time.end() and (*start_p).first > (*end_p).first) {
                max_pred = max(max_pred, (*end_p).second);
                end_p = next(end_p);
            }
            max_val = max(max_pred + (*start_p).second, max_val);
            cout << max_val space << max_pred space << (*start_p).second << endl;
            start_p = next(start_p);
        }
        return max_val;
    }
};