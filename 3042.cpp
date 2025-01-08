#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].length() >= words[j].length() and words[i].compare(0,words[j].length(),words[j]) == 0 and words[i].compare(words[i].length() - words[j].length(), words[j].length(),words[j]) == 0) res++;
            }
        }
        return res;
    }
};