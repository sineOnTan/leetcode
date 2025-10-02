#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = 0;
        res += numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            numExchange++;
            res++;
            numBottles++;
        }
        return res;
    }
};