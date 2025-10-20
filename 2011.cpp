#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cur = 0;
        for (auto i : operations) {
            if (i == "X++" or i == "++X") cur++;
            else cur--;
        }
        return cur;
    }
};