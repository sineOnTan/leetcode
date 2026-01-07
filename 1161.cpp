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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> next;
        vector<TreeNode*> cur;

        cur.push_back(root);

        int best_sum = INT_MIN;
        int best_level = 1;

        for (int i = 1; cur.size() != 0; i++) {
            int sum = 0;
            for (auto i : cur) {
                sum += i->val;
                if (i->left != nullptr)
                    next.push_back(i->left);
                if (i->right != nullptr)
                    next.push_back(i->right);
            }
            if (sum > best_sum) {
                best_sum = sum;
                best_level = i;
            }

            swap(next, cur);
            next.clear();
        }
        return best_level;
    }
};