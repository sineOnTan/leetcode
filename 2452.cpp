#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for (auto i : queries) {
            for (auto j : dictionary) {
                int diff = 0;
                for (int k = 0; k < i.size(); k++) {
                    if (i[k] != j[k]) diff++;
                }
                if (diff <= 2) {res.push_back(i); break;}
            }
        }
        return res;
    }
};