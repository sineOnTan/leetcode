using namespace std;

#include <bits/stdc++.h>


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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> cur;
        vector<TreeNode*> next;

        int max_val = INT_MIN;

        if (root != nullptr) cur.push_back(root);

        while (cur.size() != 0) {
            TreeNode* cur_node = cur.back();
            cur.pop_back();
            max_val = max(max_val, cur_node->val);
            if (cur_node->left != nullptr) next.push_back(cur_node->left);
            if (cur_node->right != nullptr) next.push_back(cur_node->right);


            if (cur.size() == 0) {
                swap(cur, next);
                res.push_back(max_val);
                max_val = INT_MIN;
            }
        }
        return res;
    }
};