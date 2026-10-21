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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return build(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        if(left > right) return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;
        root->left = build(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = build(preorder, inorder, preIdx, inIdx+1, right);
        return root;
    }
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i = left; i<=right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }
};