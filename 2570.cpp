#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            map<int,int> m;
            for (auto i : nums1) m[i[0]] += i[1];
            for (auto i : nums2) m[i[0]] += i[1];
            vector<vector<int>> res;
            for (auto i : m) {
                vector<int> temp;
                temp.push_back(i.first);
                temp.push_back(i.second);
                res.push_back(temp);
            }
            return res;
        }
    };