#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for (auto i : nums) {
            int count_nums = 0;
            int sum = 0;

            for (int j = 1; j * j <= i ; j++) {
                if (i % j == 0) {
                    count_nums += 2;
                    if (j == i / j) count_nums = 10;
                    sum += j;
                    sum += i / j;
                }
            }
            if (count_nums == 4) res += sum;
        }

        return res;
    }
};