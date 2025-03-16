#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            int compress[101] = {0};
            for (auto i : ranks) compress[i]++;

            long long lo = 0;
            long long hi = 1e14 + 5;
            long long bestSoFar = hi;
            while (lo <= hi) {
                long long mid = (hi + lo) / 2;
                long long count = 0;
                for (int i = 1; i < 101; i++) {
                    if (compress[i] > 0) count += (long long)(sqrt(mid / i)) * compress[i];
                }
                cout << mid << " " << count << endl;
                if (count >= cars) {bestSoFar = mid; hi = mid - 1;}
                else lo = mid + 1;
            }
            cout << bestSoFar << endl;
            return bestSoFar;
        }
    };