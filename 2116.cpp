#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int free = 0;
        int open = 0;
        if (s.size() % 2 != 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                free++;
            } else if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open > 0) open--;
                else free--;
                if (free < 0) return false;
            }
        }

        if (open > 0) return false;
        free = 0;
        int close = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                free++;
            } else if (s[i] == ')') {
                close++;
            } else if (s[i] == '(') {
                if (close > 0) close--;
                else free--;
                if (free < 0) return false;
            }
        }
        if (close > 0) return false;
        return true;
    }
};