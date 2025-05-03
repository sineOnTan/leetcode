#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int min_flips = INT_MAX;
            for (int i = 1; i <= 6; i++) {
                int cur = 0;
                for (int j = 0; j < tops.size(); j++) {
                    if (tops[j] == i) continue;
                    else if (bottoms[j] == i) cur++;
                    else {
                        cur = INT_MAX;
                        break;
                    }
                }
                min_flips = min(cur, min_flips);

                cur = 0;
                for (int j = 0; j < tops.size(); j++) {
                    if (bottoms[j] == i) continue;
                    else if (tops[j] == i) cur++;
                    else {
                        cur = INT_MAX;
                        break;
                    }
                }
                min_flips = min(cur, min_flips);
            }
            if (min_flips == INT_MAX) return -1;
            else return min_flips;
        }
    };