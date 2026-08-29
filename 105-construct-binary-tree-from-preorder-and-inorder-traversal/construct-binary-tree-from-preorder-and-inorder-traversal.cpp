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
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

       TreeNode* ans = helper(preorder, inorder, 0, n - 1);
       return ans;
    }
     TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int low,int high){
        if(low>high){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = mp[node->val];
        node->left = helper(preorder,inorder,low,id-1);
        node->right = helper(preorder,inorder,id+1,high);

        return node;
    }
};