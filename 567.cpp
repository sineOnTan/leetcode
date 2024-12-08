#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a[30];
        if (s1.size() > s2.size()) return false;        
        for (int i = 0; i < 30; i++) a[i] = 0;
        for (auto i : s1) ++a[i - 'a'];
        for (int i = 0; i < s1.size(); i++) --a[s2[i] - 'a'];
        bool flag = true;
        for (int j = 0; j < 30; j++) if (a[j] != 0) flag = false;
        if (flag) return true;
        for (int i = s1.size(); i < s2.size(); i++) {
            ++a[s2[i - s1.size()] - 'a'];
            --a[s2[i] - 'a'];
            flag = true;
            for (int j = 0; j < 30; j++) if (a[j] != 0) flag = false;
            if (flag) return true;
        }
        return false;
    }
};