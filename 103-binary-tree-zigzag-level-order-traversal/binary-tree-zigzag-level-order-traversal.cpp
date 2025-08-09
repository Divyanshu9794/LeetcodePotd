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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans ;
        }
        queue<TreeNode* > q;
        q.push(root);
        bool ltor = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                TreeNode* node= q.front();
                q.pop();
                int index = (ltor) ? i:(n-1-i);
                level[index] = node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ltor =!ltor;
            ans.push_back(level);
        }
        return ans ;
    }
};