#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int mod = 1e9 + 7;

class Solution {
public:
    vector<long long> subtrees;
    int maxProduct(TreeNode* root) {
        subtreeSum(root);
        long long best = 0;

        for (auto i : subtrees) best = max((subtrees.back() - i) * i, best);
        return best % mod;
    }

    int subtreeSum(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int temp = subtreeSum(cur->left) + subtreeSum(cur->right) + cur->val;
        subtrees.push_back(temp);
        return temp;
    }
};