using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int minLength(string s) {
        stack<char> q;
        for (auto i : s) {
            if (((i == 'B' and q.top() == 'A') or (i == 'D' and q.top() == 'C')) and (q.size() != 0)) q.pop();
            else q.push(i);
        }
        return q.size();
    }
};