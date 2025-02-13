#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<long long>& nums, long long k) {
            priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
            for (auto i : nums) {
                pq.push(i);
            }
            int res = 0;
            while (pq.top() < k) {
                auto x = pq.top();
                pq.pop();
                auto y = pq.top();
                pq.pop();
                pq.push(min(x,y) * 2 + max(x,y));
                res++;
            }
            return res;
        }
    };