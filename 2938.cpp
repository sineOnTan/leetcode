#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        long long count = 0;
        for(int i = 0; i < s.size();i++) if(s[i] == '0') res+=i - count--;
        return res; 
    }
};