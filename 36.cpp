#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        for (int i = 0; i < 9; i++) {
            set<int> nums;
            for (int j = 0; j < 9; j++) {
                if (nums.find(board[i][j]) != nums.end() and board[i][j] != '.') {
                    res = false;
                }
                nums.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            set<int> nums;
            for (int i = 0; i < 9; i++) {
                if (nums.find(board[i][j]) != nums.end() and board[i][j] != '.') {
                    res = false;
                }
                nums.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                set<int> nums;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (nums.find(board[i * 3 + k][j * 3 + l]) != nums.end() and board[i * 3 + k][j * 3 + l] != '.') {
                            res = false;
                        }
                        nums.insert(board[i * 3 + k][j * 3 + l]);
                    }
                }
            }
        }

        return res;
    }
};