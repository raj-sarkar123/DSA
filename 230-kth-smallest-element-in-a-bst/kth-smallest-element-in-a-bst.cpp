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
    void inorderMaker(TreeNode* root,vector<int>& arr){
        if(root==nullptr){
            return;
        }
        inorderMaker(root->left,arr);
        arr.push_back(root->val);
        inorderMaker(root->right,arr);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorderMaker(root,arr);
        // for(int i=0;i<arr.size();i++){
        //     if(i==k){
        //         return arr[i];
        //     }
        // }
        return arr[k-1];
    }
};