#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int polar = groups[0];
        res.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != polar) {
                polar = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};