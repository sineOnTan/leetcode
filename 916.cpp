#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        const int N = 27;

        vector<string> res;
        int a[N];
        int cur[N];

        for (int i = 0; i < N; i++) {
            a[i] = 0;
            cur[i] = 0;
        }

        for (auto i : words2) {
            for (auto j : i) cur[j - 'a']++;
            for (int j = 0; j < N; j++) {
                a[j] = max(a[j], cur[j]);
                cur[j] = 0;
            }
        }

        for (auto i : words1) {
            for (auto j : i) cur[j - 'a']++;
            bool flag = true;
            for (int j = 0; j < N; j++) {
                if (cur[j] < a[j]) flag = false;
                cur[j] = 0;
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};