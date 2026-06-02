#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            bool seen_upper = false;
            bool seen_lower = false;
            bool flag = true;

            for (auto c : word) {
                if (c == i + 'A') seen_upper = true;

                if (c == i + 'a') {
                    seen_lower = true;
                    if (seen_upper) flag = false;
                }
            }
            if (seen_upper and seen_lower and flag) res++;
        }
        return res;
    }
};