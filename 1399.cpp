#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countLargestGroup(int n) {
            const int N = 11;
            int a[N];
            for (int i = 0; i < N; i++) a[i] = 0;

            for (int i = 1; i <= n; i++) {
                int temp = i;
                int count = 0;
                while (temp != 0) {
                    count += temp % i;
                    temp /= 10;
                }
                a[count]++;
            }
            
            int res = 0;
            int max = 0;
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
                if (a[i] > max) {
                    res = 1;
                    max = a[i];
                } else if (a[i] == max) {
                    res++;
                }
            }
            return res;
        }
    };