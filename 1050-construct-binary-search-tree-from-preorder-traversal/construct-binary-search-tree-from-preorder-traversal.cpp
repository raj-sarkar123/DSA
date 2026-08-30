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
    int idx = 0;
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& preorder, int low, int high) {
        if (low > high) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = mp[node->val];
        node->left = helper(preorder, low, id - 1);
        node->right = helper(preorder, id + 1, high);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* res = helper(preorder, 0, preorder.size() - 1);

        return res;
    }
};