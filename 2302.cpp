#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long sum = 0;
            long long length = 0;
            int end_index = 0;
            while (sum * length < k and end_index < nums.size()) {
                sum += nums[end_index];
                length++;
                end_index++;
            }
            end_index--;
            long long res = 0;
            int cur = 0;
            for (auto i : nums) {
                while (sum * length < k and end_index < nums.size()) {
                    sum += nums[end_index];
                    length++;
                }
                end_index--;
                res += end_index - cur;
                cur++;
                sum -= i;
                length--;
            }
            return res;
        }
    };