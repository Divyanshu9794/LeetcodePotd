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
    int count = 0;
    int ans;
    void inorder(TreeNode *root, int K){
        if(root == NULL){
            return ;
        }
        inorder(root->left,K);
        if(count == K-1){
            ans = root->val;
        }
        count++;
        inorder(root->right,K);
    }
    int kthSmallest(TreeNode* root, int K) {
        inorder(root,K);   
        if(count < K){
            return -1;
        }
        return ans;
    }
};