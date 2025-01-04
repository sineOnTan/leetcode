#include <bits/stdc++.h>

using namespace std;

const int N = 30;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int char_count[N];
        int seen_char_count[N];

        bool seen_trips[N][N];

        for (int i = 0; i < N; i++) {
            char_count[i] = 0;
            seen_char_count[i] = 0;
            for (int j = 0; j < N; j++) {
                seen_trips[i][j] = false;
            }
        }

        for (auto i : s) char_count[i - 'a']++;

        for (auto i : s) {
            char_count[i - 'a']--;
            for (int j = 0; j < N; j++) {
                if(char_count[j] != 0 and seen_char_count[j] != 0) seen_trips[i - 'a'][j] = true;
            }
            seen_char_count[i - 'a']++;
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(seen_trips[i][j] == true) res++;
            }
        }
        return res;
    }
};