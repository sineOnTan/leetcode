#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n != 0) {
                if (n % 3 != 0 and n % 3 != 1) return false;
                n /= 3;
            }
            return true;
        }
    };