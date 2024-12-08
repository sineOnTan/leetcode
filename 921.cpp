#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int res = 0;
        for (auto i : s) {
            if (i == '(') open++;
            else if (open == 0) res++;
            else open--;
        }
        return res + open;
    }
};