#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        auto end = --skill.end();
        auto begin = skill.begin();
        long long s = *end + *begin;
        long long res = 0;
        while (begin < end) {
            if (*begin + *end != s) return -1;
            res += *begin * *end;
            ++begin;
            --end;
        }
        return res;
    }
};