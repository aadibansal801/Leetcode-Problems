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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIdx = 0;
        return build(preorder, preIdx, INT_MIN, INT_MAX);
    }
    TreeNode* build(vector<int>&preorder, int& preIdx, int low, int high){
        if(preIdx == preorder.size()) return nullptr;
        if(preorder[preIdx] < low || preorder[preIdx] > high) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;
        root->left = build(preorder, preIdx, low, root->val);
        root->right = build(preorder, preIdx, root->val, high);
        return root;
    }
};