#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        set<char> nums;
        for (int i = 1; i <= n; i++) nums.insert(i + '0');
        string res;
        k -= 1;

        for (int i = 0; i < n; i++) {
            if (n - i >= 3) {
                int adv = k / int(tgamma(n - i));
                k %= int(tgamma(n - i));
                auto pointer = nums.begin();
                for (int i = 0; i < adv; i++) pointer++;
                res += (*pointer);
                nums.erase(pointer);
            } else {
                if (k == 1) {
                    auto pointer = nums.begin();
                    pointer++;
                    res += *pointer;
                    nums.erase(pointer);
                    k = 0;
                } else {
                    auto pointer = nums.begin();
                    res += *pointer;
                    nums.erase(pointer);
                }
            }
        }
        return res;
    }
};