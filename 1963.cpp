#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwaps(string s) {
        int res = 0;
        int opens = 0;
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            while (s[end] != ']') end--;

            if (s[begin] == '[') opens++;
            else if (s[begin] == ']') {
                if (opens > 0) opens--;
                else {
                    s[begin] == '[';
                    s[end] == ']';
                    opens++;
                    end--;
                    res++;
                }
            }

            begin++;
        }
        return res;
    }
};