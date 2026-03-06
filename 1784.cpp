#include <bits/stdc++.h>
using namespace std;
#define space << " "

class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
                while (s[i] == '1') i++;
            }
        }
        if (count <= 1) return true;
        return false;
    }
};