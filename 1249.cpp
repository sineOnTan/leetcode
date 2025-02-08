#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string minRemoveToMakeValid(string s) {
            string res;
            int opens = 0;
            stack<string> sta;
            for (auto i : s) {
                if (i == '(') {
                    opens++;
                    sta.push("(");
                } else if (i == ')') {
                    if (opens != 0) {
                        opens--;
                        string temp = ")";
                        while (sta.top() != "(") {
                            cout << sta.top() << " ";
                            temp = sta.top() + temp;
                            sta.pop();
                            cout << temp << endl;
                        }
                        sta.pop();
                        temp = "(" + temp;
                        sta.push(temp);
                    }
                } else {
                    string temp;
                    temp += i;
                    sta.push(temp);
                }
            }
            while (sta.size() != 0) {
                if (sta.top() == "(") {sta.pop(); continue;}
                res = sta.top() + res;
                sta.pop();
            }


            return res;
        }
    };