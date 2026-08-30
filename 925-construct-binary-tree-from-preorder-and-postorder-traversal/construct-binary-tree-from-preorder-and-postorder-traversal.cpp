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

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }

        TreeNode* ans = helper(preorder, postorder, 0, n - 1);
        return ans;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int low,
                     int high) {
        if (low > high) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        if (low == high)
            return node;
        int leftroot = preorder[idx];
        int leftrootIdx = mp[leftroot];

        int id = leftrootIdx;
        node->left = helper(preorder, postorder, low, id);
        node->right = helper(preorder, postorder, id + 1, high-1);

        return node;
    }
};