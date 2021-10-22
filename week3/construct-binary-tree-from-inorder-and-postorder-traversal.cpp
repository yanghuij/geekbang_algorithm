//106. 从中序与后序遍历序列构造二叉树
//https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idx_map[inorder[i]] = i;
        }
        return doBuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* doBuildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int posStart, int posEnd) {
        int i;

        if (inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode();
        root->val = postorder[posEnd];

        i = idx_map[root->val];

        root->left =  doBuildTree(inorder, inStart, i - 1, postorder, posStart, posStart + (i - 1 - inStart));
        root->right = doBuildTree(inorder, i + 1, inEnd, postorder,  posStart + (i - 1 - inStart + 1), posEnd - 1);

        return root;
    }

    unordered_map<int, int> idx_map;
};
