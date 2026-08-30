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
    
    void inorderMake(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        inorderMake(root->left, arr);
        arr.push_back(root->val);
        inorderMake(root->right, arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorderMake(root, arr);

        TreeNode* ans = helper(root, arr, 0, arr.size() - 1);
        return ans;
    }

    TreeNode* helper(TreeNode* root, vector<int>& arr, int low, int high) {
        if(low>high){
            return nullptr;
        }
        int mid = low + (high-low)/2;
        TreeNode* heart = new TreeNode(arr[mid]);

        heart->left = helper(root,arr,low,mid-1);
        heart->right = helper(root,arr,mid+1,high);

        return heart;

    }
};