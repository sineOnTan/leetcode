#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        const int N = 500;
        int p[N];
        for (int i = 0; i < N; i++) p[i] = i;

        for (auto i : equations) {
            if (i[1] == '=') {
                auto l_1 = i[0];
                auto l_2 = i[3];

                while (p[l_1] != l_1) {
                    l_1 = p[l_1];
                }

                while (p[l_2] != l_2) {
                    l_2 = p[l_2];
                }

                p[l_1] = l_2;
            }
        }

        for (auto i : equations) {
            if (i[1] == '!') {
                auto l_1 = i[0];
                auto l_2 = i[3];

                while (p[l_1] != l_1) {
                    l_1 = p[l_1];
                }

                while (p[l_2] != l_2) {
                    l_2 = p[l_2];
                }

                if (l_1 == l_2) return false;
            }
        }

        return true;
    }
};