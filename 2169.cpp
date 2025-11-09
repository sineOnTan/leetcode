#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 or num2 == 0) return 0;

        if (num1 < num2) swap(num1, num2);
        return countOperations(num1 - num2, num2) + 1;
    }
};