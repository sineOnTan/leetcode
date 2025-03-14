#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long hi = 0;
            long long lo = 0;
            long long bestsofar = 0;
            for (auto i : candies) hi += i;
            hi /= k;
            hi += 1;
            
            while (lo <= hi) {
                priority_queue<int> pq;
                for (auto i : candies) pq.push(i);

                int mid = (hi + lo) / 2;
                cout << mid << " " << lo << " " << hi << endl;

                long long cur = 0;
                if (mid == 0) cur = k;
                else for (auto i : candies) cur += i/mid;

                if (cur >= k) {lo = mid + 1; bestsofar = mid;}
                else hi = mid - 1;
            }
            return bestsofar;
        }
    };