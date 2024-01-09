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
    void dfs(TreeNode*r,vector<int>&aux){
        if(!r)return;
        dfs(r->left,aux);
        if(!r->left && !r->right)aux.push_back(r->val);
        dfs(r->right,aux);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1,r2;
        dfs(root1,r1);
        dfs(root2,r2);
        return r1==r2;
    }
};