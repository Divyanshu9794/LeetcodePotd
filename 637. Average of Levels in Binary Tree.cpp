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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> v;
        if(root==NULL){
            return ans ;
        }
        queue<TreeNode* > q;
        q.push(root);
        while(q.empty()==false){
            int c=q.size();
            for(int i=0;i<c;i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }

            }
            double f = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
            v.clear();
            ans.push_back(f);
        }
        return ans;
        
    }
};
