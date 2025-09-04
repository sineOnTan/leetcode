#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<pair<int,int>,int>> vec;
        for (auto i : points) vec.emplace_back(i[0], i[1]);

        
        constexpr bool operator()(const T& lhs, const T& rhs) const 
        {
            return lhs > rhs; // assumes that the implementation handles pointer total order
        }

        sort(vec.begin(), vec.end(),)
    }
};