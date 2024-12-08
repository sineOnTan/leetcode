#include <bits/stdc++.h>
#include <numeric>


using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        priority_queue<pair<int,int>> times;
        int result = INT_MAX;
        for (auto i : timePoints) {
            auto h1 = i[0];
            auto h2 = i[1];
            auto m1 = i[3];
            auto m2 = i[4];
            string hour = "";
            hour += h1;
            hour += h2;
            string minute = "";
            minute += m1;
            minute += m2;
            times.push(make_pair(stoi(hour), stoi(minute)));
        }

        auto first = times.top();
        pair<int,int> previous = make_pair(100,100);

        while (!times.empty()) {
            auto temp = times.top();
            cout << temp.first <<" " << temp.second << endl;
            int minutes = 0;
            minutes += previous.first - temp.first;
            minutes *= 60;
            minutes += previous.second - temp.second;
            result = min(result, minutes);
            previous = temp;
            times.pop();
            cout << result << endl;
        }
        int minutes = 0;
        minutes += previous.first - first.first + 24;
        minutes *= 60;
        minutes += previous.second - first.second;
        cout << minutes;
        result = min(result, minutes);
        // cout << minutes << endl;

        return result;
    }
};