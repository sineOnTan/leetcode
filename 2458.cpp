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

const int N = 1e5 + 10;
int heights[N];
map<TreeNode*, TreeNode*> ma;
map<int, TreeNode*> node_map;



class Solution {
public:
    int get_heights(TreeNode* root) {
        if (root == nullptr) return -1;
        ma[root->left] = root;
        ma[root->right] = root;
        node_map[root->val] = root;
        heights[root->val] = max(get_heights(root->left), get_heights(root->right)) + 1;
        return heights[root->val];
    }

    int height(TreeNode* cur, TreeNode* del) {
        if (cur->left != del) {
            if (cur->left == nullptr) return -1;
            else return heights[cur->left->val];
        }
        else if (cur->right != del) {
            if (cur->right == nullptr) return -1;
            else return heights[cur->right->val];
        }
        else return 1000;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ma.clear();
        get_heights(root);
        vector<int> res;


        for(auto i : queries) {
            auto pred_node = node_map[i];
            auto cur_node = ma[pred_node];

            int re = height(cur_node, pred_node);
            while(cur_node != root) {
                pred_node = cur_node;
                cur_node = ma[cur_node];
                re = max(height(cur_node, pred_node), re + 1);
                if (re == height(cur_node, pred_node)) {re = heights[root->val]; break;}
            }
            res.push_back(re + 1);

        }
        return res;
    }
};