#include <compare>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int upper_bound = 31;
        int lower_bound = 0;
        int current = 16;
        while (current != lower_bound) {
            long long x = pow(2, current);
            cout << x << endl;
            if (x > num) {
                upper_bound = current;
                current = upper_bound + lower_bound;
                current /= 2;
            } else {
                lower_bound = current;
                current = upper_bound + lower_bound;
                current /= 2;
            }
        }
        long long x = pow(2, upper_bound) - 1 - num;

        return x;
    }
};