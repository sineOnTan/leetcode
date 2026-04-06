#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,int> m_pos_to_index;
        map<int,pair<int,string>> order_robots;


        for (int i = 0; i < positions.size(); i++) {
            m_pos_to_index[positions[i]] = i;
        }

        for (int i = 0; i < positions.size(); i++) {
            order_robots[positions[i]] = make_pair(healths[i], directions[i]);
        }

        vector<pair<int,int>> left_robot_hp_pos;

        for (auto i : order_robots) {
            
        }

    }
};