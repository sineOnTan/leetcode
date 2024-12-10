#include <bits/stdc++.h>
using namespace std;



#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maximumLength(string s) {
        int a[60][60];
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                a[i][j] = 0;   
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (s[i] == s[j] and j < s.size()) {
                j++;
                a[s[i] - 'a'][j - i]++;
            }

        }
        int res = -1;
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                if(a[i][j] >= 3) res = max(res,j);
            }
        }
        return res;
    }
};