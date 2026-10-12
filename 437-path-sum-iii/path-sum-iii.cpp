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
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        dfs(root, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum){
        if(!root) return;
        findPaths(root, 0, targetSum);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
    }
    void findPaths(TreeNode* node, long long sum, int targetSum){
        if(!node) return;
        sum+=node->val;
        if(sum==targetSum){
            ans++;
        }
        findPaths(node->left, sum, targetSum);
        findPaths(node->right, sum, targetSum);
    }
};