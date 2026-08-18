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
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        helper(root, maxSum);
        return maxSum;
    }

    int helper(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        int leftSum = max(0, helper(root->left, maxSum));
        int rightSum = max(0, helper(root->right, maxSum));
        maxSum = max(maxSum, leftSum + rightSum + root->val);

        return root->val + max(leftSum, rightSum);
    }
};
