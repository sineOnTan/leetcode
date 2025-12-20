#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            string temp;
            for (auto j : strs) {
                temp.push_back(j[i]);
            }

            if (!is_sorted(temp.begin(), temp.end())) res++;
        }
        return res;
    }
};