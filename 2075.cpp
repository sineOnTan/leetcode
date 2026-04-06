#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res = "";
        for (int i = 0; i < (encodedText.size() / rows); i++) {
            for (int j = 0; j < rows and i + j < (encodedText.size() / rows); j++) {
                res.push_back(encodedText[i + j * ((encodedText.size() / rows) + 1)]);
            }
        }
        while(*res.rbegin() == ' ') {
            res.pop_back();
        }
        return res;
    }
};