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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int sidx = q.front().second;
            int eidx = q.back().second;
            maxWidth = max(maxWidth, eidx - sidx + 1);
            for(int i = 0; i<size; i++){
                auto [node,idx] = q.front();
                q.pop();
                if(node->left) q.push({node->left, (long long)2*idx+1});
                if(node->right) q.push({node->right, (long long)2*idx+2});
            }
        }
        return maxWidth;
    }
};