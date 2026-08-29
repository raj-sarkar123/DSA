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
    int idx;
    unordered_map<int, int> mp;
   
    
    
     TreeNode* helper( vector<int>& postorder,int low,int high){
        if(low>high){
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = mp[node->val];
        node->right = helper(postorder,id+1,high);
        node->left = helper(postorder,low,id-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        idx = n-1;
       TreeNode* ans = helper(postorder, 0, n - 1);
       return ans;
    }
};