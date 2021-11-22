//124. 二叉树中的最大路径和
//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
//如何打印方案?????
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
        ans = -1e9;
        dfs(root);
        return ans;
    }

private:
    int dfs(TreeNode* root) {
        if (root == nullptr) 
            return 0;

        int leftValue = max(dfs(root->left), 0);
        int rightValue = max(dfs(root->right), 0);

        ans = max(ans, root->val + leftValue + rightValue);

        return root->val + max(leftValue, rightValue);
    }

    int ans;
};
