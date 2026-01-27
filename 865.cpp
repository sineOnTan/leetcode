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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* res;
    map<int,pair<int,int>> m;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        res = root;
        getHeight(root);
        while (m[res->val].first != m[res->val].second) {
            if (m[res->val].first > m[res->val].second) res = res->left;
            else res = res->right;
        }
        return res;
    }

    int getHeight(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int leftHeight = getHeight(cur->left);
        int rightHeight = getHeight(cur->right);

        m[cur->val] = make_pair(leftHeight, rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }
};