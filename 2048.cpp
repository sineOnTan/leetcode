#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while (true) {
            map<int,int> m;
            int temp = n;
            while (temp != 0) {
                m[temp % 10]++;
                temp %= 10;
            }
            bool flag = true;
            for (auto i : m) if (i.first != i.second) flag = false;

            if (flag) return n;

            n++;
        }
    }
};