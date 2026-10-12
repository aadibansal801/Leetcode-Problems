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
    unordered_map<long long, int> prefix;
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        prefix.clear();
        prefix[0] = 1;
        dfs(root, 0, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, long long currSum, int targetSum){
        if(!root) return;
        currSum += root->val;
        ans += prefix[currSum - targetSum];
        prefix[currSum]++;
        dfs(root->left, currSum, targetSum);
        dfs(root->right, currSum, targetSum);
        prefix[currSum]--;
    }
};