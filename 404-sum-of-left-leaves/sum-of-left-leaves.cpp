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
     int solve(TreeNode* root, char dir){
        
        if(root==NULL)return 0;
        int left  = solve(root->left,'l');
        int right = solve(root->right,'r');
        int sum=0;
        if(root->left==NULL && root->right ==NULL && dir =='l')
            sum+=root->val;
        return sum + left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,'c');
    }
};