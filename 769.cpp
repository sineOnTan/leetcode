#include <bits/stdc++.h>
using namespace std;

// Finds max of predecessors and checks if it is equal to the index.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int num = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            num = max(num, arr[i]);
            if (num == i) res++;
        }
        return res;
    }
};