#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (auto i : gifts) {
            pq.push(i);
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            auto temp = pq.top();
            pq.pop();
            pq.push(floor(sqrt(temp)));
        }
        while(pq.size() != 0) {
            res += pq.top();
            pq.pop();
        }
        
        return res;
    }
};