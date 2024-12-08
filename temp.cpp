#include <compare>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <set>
#include <string>
#include <vector>
#include <hash_map>
#include <map>

using namespace std;

int result = 0;

vector<set<int>> rangeT;
string s1;
int result = 0;

class Solution {
public:
    void findPrints(int front, int back) {
        for (int i = front; i <= back; i++) {

        }
    }


    int strangePrinter(string s) {
        int i = 0;
        char t = s[0];
        s1.push_back(t);
        rangeT[s[0] - 'a'].insert(i);
        for (char c : s) {
            if (c == t) {
                continue;
            } else {
                rangeT[c - 'a'].insert(i);
                s1.push_back(c);
                ++i;
                t = c;
            }
        }

        int front = 0;
        int back = s1.length();

        findPrints(front, back);
        return result;
    }
};