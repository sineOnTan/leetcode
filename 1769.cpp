#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int N = boxes.size();
        int a[N];

        int count = 0;
        int balls = 0;
        for (int i = 0; i < N; i++) {
            a[i] = count;
            balls += boxes[i] - '0';
            count += balls;
        }

        count = 0;
        balls = 0;
        for (int i = N - 1; i >= 0; i--) {
            a[i] += count;
            balls += boxes[i] - '0';
            count += balls;
        }
        
        vector<int> res;
        for (int i = 0; i < N; i++) {
            res.push_back(a[i]);
        }
        return res;
    }
};