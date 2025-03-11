#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int a[3];
            a[0] = 0; a[1] = 0; a[2] = 0;
            int b_index = 0;
            int f_index = 0;
            int res = 0;
            while (b_index != s.size()) {
                if (a[0] >= 1 and a[1] >= 1 and a[2] >= 1) {
                    res += s.size() - f_index;
                    a[s[b_index] - 'a']--;
                    b_index++;
                } else {
                    while (a[0] < 1 or a[1] < 1 or a[2] < 1) {
                        if (f_index >= s.size()) break;
                        a[s[f_index] - 'a']++;
                        f_index++;
                    }
                    if (f_index >= s.size() and (a[0] < 1 or a[1] < 1 or a[2] < 1)) break;
                    res += s.size() - f_index;
                    a[s[b_index] - 'a']--;
                    b_index++;
                }
            }
            return res;
        }
    };