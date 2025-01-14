#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        set<int> a;
        set<int> b;
        int t = 0;
        for (int i = 0; i < A.size(); i++) {
            a.insert(A[i]);
            if (b.contains(A[i])) t++;
            b.insert(B[i]);
            if (a.contains(B[i])) t++;
            res.push_back(t);
        }
        return res;
    }
};