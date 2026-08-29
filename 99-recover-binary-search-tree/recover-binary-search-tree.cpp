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
    TreeNode* prev = nullptr;
    int wrong = 0;
    TreeNode* wrong1 = nullptr;
    TreeNode* wrong2 = nullptr;
    TreeNode* wrong3 = nullptr;
    TreeNode* wrong4 = nullptr;
    void validInorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        validInorder(root->left);
        if (prev == nullptr) {
            prev = root;
        } else {
            if (prev->val > root->val) {
                if (wrong == 0) {
                    wrong1 = prev;
                    wrong2 = root;
                    wrong++;
                } else {
                    wrong3 = prev;
                    wrong4 = root;
                    wrong++;
                }
            }
            prev = root;
        }
        validInorder(root->right);
       
    }
    void recoverTree(TreeNode* root) {
        validInorder(root);
        if (wrong == 1) {
            swap(wrong1->val, wrong2->val);
        } else {
            swap(wrong1->val, wrong4->val);
        }
    }
};