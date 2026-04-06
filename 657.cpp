#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int right = 0;
        for (auto i : moves) {
            if (i == 'U') up++;
            if (i == 'D') up--;
            if (i == 'R') right++;
            if (i == 'L') right--;
        }
        return up == 0 and right == 0;
    }
};