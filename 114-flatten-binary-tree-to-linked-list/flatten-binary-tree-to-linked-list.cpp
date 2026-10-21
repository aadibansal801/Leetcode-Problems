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

    vector<TreeNode*> nodes;

    void preorder(TreeNode* root){
        if(root == nullptr) return;
        nodes.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }

    void flatten(TreeNode* root) {
        if(!root) return;
        nodes.clear();
        preorder(root);
        for(int i = 0; i<nodes.size()-1; i++){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};