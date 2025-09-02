#include <bits/stdc++.h>
using namespace std;
#define space << " "

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        for (auto i : points) {
            for (auto j : points) {
                if (i[0] < j[0] or i[1] > j[1]) continue;
                else if (i == j) continue;
                bool flag = true;
                for (auto k : points) {
                    if (flag == false) break;
                    else if (i == k or j == k) continue;


                    if (k[0] > i[0] or k[0] < j[0] or k[1] > j[1] or k[1] < i[1]) continue;
                    else flag = false;
                }

                if (flag) res++;
            }
        }
        return res;
    }
};