#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int direction = 0;
        int current_x = 0;
        int current_y = 0;
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(-1);
            }
            result.push_back(temp);
        }

        while (head != nullptr) {
            result[current_y][current_x] = head->val;
            head = head->next;
            if (direction == 0) {
                if (current_x + 1 == n || result[current_y][current_x + 1] != -1) {
                    direction = 1;
                    current_y++;
                } else {
                    current_x++;
                }
            } else if (direction == 1) {
                if (current_y + 1 == m || result[current_y + 1][current_x] != -1) {
                    direction = 2;
                    current_x--;
                } else {
                    current_y++;
                }
            } else if (direction == 2) {
                if (current_x - 1 == -1 || result[current_y][current_x - 1] != -1) {
                    direction = 3;
                    current_y--;
                } else {
                    current_x--;
                }
            } else if (direction == 3) {
                if (current_y - 1 == -1 || result[current_y - 1][current_x] != -1) {
                    direction = 0;
                    current_x++;
                } else {
                    current_y--;
                }
            }
        }
        return result;
    }
};