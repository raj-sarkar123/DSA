/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (root->val < val && root->right != nullptr) {
           root->right= helper(root->right, val);
        } else if (root->val > val && root->left != nullptr) {
           root->left= helper(root->left, val);
        } else {
            if (root->val > val) {
                TreeNode* node = new  TreeNode(val);
                root->left = node;
            } else {
                TreeNode* node = new TreeNode(val);
                root->right = node;
            }
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ans = helper(root,val);
        return ans;
    }
};