#include <bits/stdc++.h>
using namespace std;
#define space << " "

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s1_1;
        string s2_1;
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                s1_1 += s1[i];
                s2_1 += s2[i];
            }
        }
        sort (s1_1.begin(), s1_1.end());
        sort (s2_1.begin(), s2_1.end());
        if (s1_1 != s2_1) return false;

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 1) {
                s1_1 += s1[i];
                s2_1 += s2[i];
            }
        }
        sort (s1_1.begin(), s1_1.end());
        sort (s2_1.begin(), s2_1.end());
        if (s1_1 != s2_1) return false;

        return true;
    }
};