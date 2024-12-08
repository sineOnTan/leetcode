#include <compare>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        int n1 = 0;
        int m1 = 0;
        for (auto num : original) {
            temp.push_back(num);
            ++n1;
            if (n == n1) {
                result.push_back(temp);
                temp.clear();
                m1++;
                n1 = 0;
            }
        }
        if (m1 != m && n == 0) {
            vector<vector<int>> t;

            return t;
        }
        return result;
    }
};