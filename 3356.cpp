#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int j_q = 0;
            int i = 0;
            int neg = 0;
            unordered_map<int,int> num_negs;
            while (i < nums.size()) {
                cout << j_q << " " << neg << " " << num_negs[i] << " " << i << endl;
                neg += num_negs[i];
                if (nums[i] - neg <= 0) i++;
                else {
                    while (nums[i] - neg > 0) {
                        if (j_q >= queries.size()) return -1;

                        if (queries[j_q][0] <= i) neg += queries[j_q][2];
                        else num_negs[queries[j_q][0]] += queries[j_q][2];

                        if (queries[j_q][1] < i) neg -= queries[j_q][2];
                        else num_negs[queries[j_q][1] + 1] -= queries[j_q][2];

                        j_q++;
                    }
                    i++;
                }
            }
            return j_q;
        }
    };