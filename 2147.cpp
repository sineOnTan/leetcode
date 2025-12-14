#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string corridor) {
        long long count = 0;
        for (auto i : corridor) if (i == 'S') count++;
        if (count % 2 != 0 or count == 0) return 0;
        
        string filtered_corridor;
        long long chair_count = 0;
        long long plants = 1;
        long long res = 1;
        for (auto i : corridor) {
            if (i == 'S') {
                chair_count++;
                if (chair_count % 2 == 1 and chair_count != 1) {
                    res *= plants;
                    plants = 1;
                    res %= mod;
                } else if (chair_count % 2 == 1) {
                    plants = 1;
                    res %= mod;
                }
            } else {
                if (chair_count % 2 == 0) plants++;
            }
        }
        return res;
    }
};