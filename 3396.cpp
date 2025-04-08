#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int i = 0;
            const int N = 110;
            int a[N];
            for (int i = 0; i < N; i++) a[i] = 0;

            int end = nums.size();
            while (end % 3 != 0 and a[nums[end - 1]] == 0) {
                a[nums[end - 1]]++; 
                end--;
            }

            while (end >= 3 and a[nums[end - 3]] == 0 and a[nums[end - 2]] == 0 and a[nums[end - 1]] == 0) {
                a[nums[end - 3]]++;
                a[nums[end - 2]]++;
                a[nums[end - 1]]++;
                if (a[nums[end - 3]] >= 2 or a[nums[end - 2]] >= 2 or a[nums[end - 1]] >= 2) break;
                end -= 3;
            }
            int res = 0;
            if (end % 3 != 0) res++;
            res += end / 3;
            return res;
        }
    };