#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_n = n / 2 + n % 2;
        long long even_n = n / 2;
        long long odd_m = m / 2 + m % 2;
        long long even_m = m / 2;
        long long res = 0;
        res += odd_n * even_m;
        res += even_n * odd_m;
        return res;
    }
};