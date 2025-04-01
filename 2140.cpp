#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            long long a[N];
            for (int i = 0; i <= questions.size(); i++) a[i] = 0;
            for (int i = 0; i < questions.size(); i++) {
                if (i >= 1) a[i] = max(a[i], a[i - 1]);
                a[min((int)questions.size(), i + questions[i][1] + 1)] = max(a[min((int)questions.size(), i + questions[i][1] + 1)], a[i] + questions[i][0]);
            }

            return a[questions.size()];
        }
    };