#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long num_negs = 0;
        long long sum = 0;
        int lowest = INT_MAX;

        for (auto row : matrix) {
            for (int i : row) {
                if (i < 0) {
                    num_negs++;
                    i *= -1;
                }
                if (i < lowest) lowest = i;
                sum += i;
            }
        }
        if (num_negs % 2 == 0) return sum;
        else return sum - lowest - lowest;
    }
};