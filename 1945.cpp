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
    int getLucky(string s, int k) {
        vector<int> things;
        for (char c : s) {
            int temp = c - 'a' + 1;
            if (temp > 9) {
                count = count * 100;
                count += temp;
            } else {
                count = count * 10;
                count += temp;
            }
        }
        for (int i = 0; i < k; i++) {
            long long temp1 = 0;
            while (count != 0) {
                temp1 *= 10;
                temp1 += count % 10;
                count = count / 10;
            }
            count = temp1;
        }
        int result = count;
        return result;
    }
};