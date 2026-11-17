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

    unordered_map<TreeNode*, TreeNode*> parent;

    string getDirections(TreeNode* root, int startValue, int destValue) {
        buildParent(root, NULL);
        TreeNode* start = findNode(root, startValue);
        queue<TreeNode*>q;
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, TreeNode*> prev;
        unordered_map<TreeNode*, char> direction;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == destValue) break;
            if(node->left && !visited.count(node->left)){
                visited.insert(node->left);
                prev[node->left] = node;
                direction[node->left] = 'L';
                q.push(node->left);
            }
            if(node->right && !visited.count(node->right)){
                visited.insert(node->right);
                prev[node->right] = node;
                direction[node->right] = 'R';
                q.push(node->right);
            }
            if(parent[node] && !visited.count(parent[node])){
                visited.insert(parent[node]);
                prev[parent[node]] = node;
                direction[parent[node]] = 'U';
                q.push(parent[node]);
            }
        }
        string ans = "";
        TreeNode* curr = findNode(root, destValue);
        while(curr != start){
            ans += direction[curr];
            curr = prev[curr];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void buildParent(TreeNode* root, TreeNode* par){
        if(root == nullptr) return;
        parent[root] = par;
        buildParent(root->left, root);
        buildParent(root->right, root);
    }
    TreeNode* findNode(TreeNode* root, int val){
        if(root == nullptr) return nullptr;
        if(root->val == val){
            return root;
        }
        TreeNode* left = findNode(root->left, val);
        if(left != nullptr) return left;
        return findNode(root->right, val);
    }
};