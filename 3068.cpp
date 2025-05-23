#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<long long>& nums, long long k, vector<vector<long long>>& edges) {
        long long res = 0;
        for (auto i : nums) res += i;

        priority_queue<long long> deltas;
        for (auto i : nums) {cout << (i ^ k) - i << '\n'; deltas.push((i ^ k) - i);}

        long long maxc = 0;
        while (deltas.size() > 1) {
            long long temp = 0;
            temp += deltas.top();
            deltas.pop();
            temp += deltas.top();
            deltas.pop();
            if (temp > 0) maxc += temp;
            else return maxc + res;
        }
        return maxc + res;
    }
};