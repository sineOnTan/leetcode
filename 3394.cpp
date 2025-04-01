#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            priority_queue<pair<int,int>> pqh;
            priority_queue<pair<int,int>> pqy;

            set<int> candidates_h;
            set<int> candidates_y;

            for (auto i : rectangles) {
                pqh.emplace(i[0],i[1]);
                pqh.emplace(i[2],i[3]);
                candidates_h.emplace(i[1]);
                candidates_y.emplace(i[3]);
            }

            for (auto i :candidates_h) {
                
            }
        }
    };