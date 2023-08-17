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
    void inorder(TreeNode* root,vector<int > &a){
        
        if(root!=NULL){
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
        }

       
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int> a;
        inorder(root,a);
        int x= a[0];
        for(int i=1;i<a.size();i++){
            if(x!=a[i]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
};
