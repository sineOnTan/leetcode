#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        string s_temp = "";
        while (s.size() != 2) {
            for (int i = 0; i < s.size() - 1; i++) {
                char temp = s[i] + s[i + 1] - '0' - '0';
                temp %= 10;
                temp += '0';
                s_temp.push_back(temp);
            }
            s = s_temp;
            s_temp = "";
        }
        return (s[1] == s[0]);
    }
};