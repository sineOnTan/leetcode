#include <bits/stdc++.h>

using namespace std;

// NOTE: Be careful of char ranges.

const int MOD = ('z' - 'a' + 1);

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int LENGTH = s.size() + 1;
        int a[LENGTH];
        for (int i = 0; i < LENGTH; i++) a[i] = 0;
        for (auto i : shifts) {
            if (i[2] == 0) {
                --a[i[0]];
                ++a[i[1] + 1];
            } else if (i[2] == 1) {
                ++a[i[0]];
                --a[i[1] + 1];
            }
        }

        int shift = 0;
        for (int i = 0; i < s.size(); i++) {
            shift = shift + a[i];
            int temp = s[i];
            temp += shift;
            s[i] = (((temp - 'a') % MOD) + MOD) % MOD + 'a';
        }
        return s;
    }
};