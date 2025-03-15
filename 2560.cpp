#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            long long hi = 1e9;
            long long lo = 0;
            long long bestsofar = 0;
            
            while (lo <= hi) {
                int count = 0;
                int mid = (hi + lo) / 2;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] <= mid) {i++; count++;}
                }

                if (count >= k) {hi = mid - 1; bestsofar = mid;}
                else lo = mid + 1;
            }
            return bestsofar;
        }
    };