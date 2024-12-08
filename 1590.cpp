#include <bits/stdc++.h>
using namespace std;

const int N = 10100;
int a[N];

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        for (int i = 0; i < N; i++) a[i] = -10100;
        int result = 10100;
        int prefix = 0;
        for (auto i : nums) {
            prefix += i;
            prefix %= p;
            result = min(a[prefix], result);
            a[prefix] = p;
        }
    }
};