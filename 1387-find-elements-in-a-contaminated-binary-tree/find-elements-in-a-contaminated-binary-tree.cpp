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
class FindElements {
public:

    TreeNode* root = nullptr;

    FindElements(TreeNode* root) {
        root->val = 0;
        this->root = root;
    }

    bool solve(TreeNode* root, int target){
        if(!root) return false;
        if(root->val == target) return true;
        bool left = false;
        bool right = false;
        if(root->left){
            root->left->val = 2 * root->val + 1;
            left = solve(root->left, target);
        }
        if(root->right){
            root->right->val = 2 * root->val + 2;
            right = solve(root->right, target);
        }
        return left || right;
    }
    
    bool find(int target) {
        return solve(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */