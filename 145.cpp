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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        if (root->left != nullptr) {
            auto t = postorderTraversal(root->left);
            result.insert(result.end(), t.begin(), t.end());
        }
        if (root->right != nullptr) {
            auto t = postorderTraversal(root->right);
            result.insert(result.end(), t.begin(), t.end());
        }
        result.push_back(root->val);
        return result;
    }
};