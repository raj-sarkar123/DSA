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
class BSTIterator {
public:
    vector<int> arr;
    int idx=0;
    void inorderMaker(TreeNode* root,vector<int>& arr){
        if(root==nullptr){
            return;
        }
        inorderMaker(root->left,arr);
        arr.push_back(root->val);
        inorderMaker(root->right,arr);

    }
    BSTIterator(TreeNode* root) {
        inorderMaker(root,arr);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */