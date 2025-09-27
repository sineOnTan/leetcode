#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double m_area = 0;
        for (auto i : points) {
            for (auto j : points) {
                for (auto k : points) {
                    double area = abs((i[0] - k[0]) * (j[1] - k[1]) - (i[1] - k[1]) * (j[0] - k[0]));
                    m_area = max(area, m_area);
                }
            }
        }
        return m_area / 2;
    }
};