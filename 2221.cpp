#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int res = 0;
        vector<int> temp = nums;
        vector<int> next;
        while (temp.size() != 1) {
            for (int i = 0; i < temp.size() - 1; i++) {
                next.push_back(temp[i] + temp[i + 1]);
            }
            swap(next,temp);
            next.clear()
        }
        return temp[0];
    }
};