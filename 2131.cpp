#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,pair<int,int>> m;
        for (auto i : words) {
            string temp = i;
            sort(temp.begin(), temp.end());

            if (temp != i) m[temp].second++;
            else m[temp].first++;
        }
        bool dual = false;
        int res = 0;
        for (auto i : m) {
            res += (min(i.second.first, i.second.second)) * 4;
            if (i.first[0] == i.first[1]) {
                res += i.second.first / 2;
                if (i.second.first % 2 == 1) dual = true;
            }
        }

        if (dual) return res + 2;
        else return res;
    }
};