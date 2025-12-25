#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (auto i : apple) sum += i;

        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());

        int res = 0;
        for (auto i : capacity) {
            cout << i << endl;
            sum -= i;
            res++;
            if (sum <= 0) return res;
        }
        return res;
    }
};