#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<pair<int,int>> mp_vec;
        map<string,string> pred;
        for (int i = 0; i < words.size(); i++) {
            int max_pred = 0;
            int max_index = -1;
            for (int j = 0; j < i; j++) {
                if (words[j].size() == words[i].size() and groups[j] != groups[i]) {
                    int diffs = 0;
                    for (int k = 0; k < words[i].size(); k++) {
                        if (words[i][k] != words[j][k]) diffs++;
                    }
                    if (diffs == 1 and mp_vec[j].first > max_pred) {
                        max_index = j;
                        max_pred = mp_vec[j].first;
                    }
                }
            }
            mp_vec.emplace_back(max_pred + 1, max_index);
        }
        int max_index = -1;
        int max_pred = 0;
        for (int i = 0; i < mp_vec.size(); i++) {
            if (mp_vec[i].first > max_pred) {
                max_pred = mp_vec[i].first;
                max_index = i;
            }
        }

        vector<string> res;
        int cur = max_index;
        while (cur != -1) {
            res.push_back(words[cur]);
            cur = mp_vec[cur].second;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};