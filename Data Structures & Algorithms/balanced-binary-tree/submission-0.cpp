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

class Solution {
   public:
    bool isBalanced(TreeNode* root) { return maxDepth(root) != -1; }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = maxDepth(root->left);
        if (leftH == -1) return -1;
        int rightH = maxDepth(root->right);
        if (rightH == -1) return -1;
        if (abs(rightH - leftH) > 1) return -1;

        return 1 + max(leftH, rightH);
    }
};
