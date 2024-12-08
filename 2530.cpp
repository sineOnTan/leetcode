#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long res = 0;

        for (auto i : nums) pq.push(i);

        while(k--) {
            res += pq.top();
            pq.push(ceil(double(pq.top()) / 3));
            pq.pop();
        }
        return res;
    }
};