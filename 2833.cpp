#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int position = 0;
        int blanks = 0;
        for (auto i : moves) {
            if (i == 'L') position++;
            else if (i == 'R') position--;
            else blanks++;
        }

        return abs(position) + blanks;
    }
};