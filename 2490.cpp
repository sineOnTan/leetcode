using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (*sentence.rbegin() != *sentence.begin()) return false;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ')
                if (sentence[i-1] != sentence[i+1]) return false;
        }
        return true;
    }
};