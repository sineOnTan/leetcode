#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowel_count;
        int c = 0;
        vowel_count.push_back(0);
        for (auto i : words) {
            if ((*i.begin() == 'a' or *i.begin() == 'e' or *i.begin() == 'i' or *i.begin() == 'o' or *i.begin() == 'u') and (*i.rbegin() == 'a' or *i.rbegin() == 'e' or *i.rbegin() == 'i' or *i.rbegin() == 'o' or *i.rbegin() == 'u')) c++;

            vowel_count.push_back(c);
        }
        vector<int> res;
        for (auto i : queries) {
            res.push_back(vowel_count[i[1] + 1] - vowel_count[i[0]]);
        }
        return res;
    }
};