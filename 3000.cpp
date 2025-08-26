#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<int> max_pair = {0,0};
        for (auto vec : dimensions) {
            if (vec[0] * vec[0] + vec[1] * vec[1] > max_pair[0] * max_pair[0] + max_pair[1] * max_pair[1]) {
                max_pair[0] = vec[0];
                max_pair[1] = vec[1];
            } else if (vec[0] * vec[0] + vec[1] * vec[1] == max_pair[0] * max_pair[0] + max_pair[1] * max_pair[1]
            and vec[0] * vec[1] > max_pair[0] * max_pair[1]) {
                max_pair[0] = vec[0];
                max_pair[1] = vec[1];
            }
        }
        return max_pair[0] * max_pair[1];
    }
};