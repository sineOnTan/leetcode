#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto i : words) {
            if (i.compare(0, pref.length(), pref) == 0) res++;
        }
        return res;
    }
};