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
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        int l = 0; int r = inorder.size()-1;
        while(l<r){
            int sum = inorder[l] + inorder[r];
            if(sum < k){
                l++;
            }else if(sum > k){
                r--;
            }else{
                return true;
            }
        }
        return false;
    }
    void inorderTraversal(TreeNode* root, vector<int>&inorder){
        if(!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};