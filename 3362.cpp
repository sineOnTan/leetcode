#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> decreases;
        priority_queue<int, vector<int>, std::greater<int>> queued;

        int negs = 0;
        int res = 0;

        sort(queries.begin(), queries.end());

        int j = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            while (queued.size() != 0 and queued.top() < i) {
                negs--;
                queued.pop();
            }

            while (j < queries.size() and queries[j][0] <= i) {
                decreases.push(queries[j][1]);
                j++;
            }

            while (negs < nums[i]) {
                if (decreases.size() != 0 or decreases.top() < i) return -1;
                queued.push(decreases.top());
                decreases.pop();
                res++;
                negs++;
            }
        }

        return queries.size() - res;
    }
};