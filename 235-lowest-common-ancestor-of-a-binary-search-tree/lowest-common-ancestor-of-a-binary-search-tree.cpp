/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root==NULL) return NULL;
        int current = root->val;
        if(current < a->val && current < b->val){
            return lowestCommonAncestor(root->right,a,b);
        }
        if(current>a->val && current>b->val){
            return lowestCommonAncestor(root->left,a,b);
        }
        return root;
    }
};