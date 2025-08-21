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
    int countnode(TreeNode* root){
        if(root == NULL) return 0;
        int ans = 1+ countnode(root->left) + countnode(root->right);
        return ans;
    }
    bool iscbt(TreeNode* root, int i, int cnt){
        if(root==NULL) return true;
        if(i>=cnt) return false;
        else{
            bool left = iscbt(root->left,2*i+1,cnt);
            bool right = iscbt(root->right,2*i+2,cnt);
            return left&&right;
        }
    }
    bool ismaxorder(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->val < root->left->val);
        }
        else{
            bool left = ismaxorder(root->left);
            bool right = ismaxorder(root->right);
            return (left&&right) && (root->val < root->left->val && root->val < root->right->val);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        int i =0;
        int count = countnode(root);
        if(iscbt(root,i,count) && ismaxorder(root)){
            return true;
        }
        return false;
    }
};