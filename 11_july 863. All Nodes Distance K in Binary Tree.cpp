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
    bool flag = false;
    void check(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root==NULL){
            return ;
        }
        if(root->val==target->val){
            flag=true;
        }
        parent[root->left]=root;
        parent[root->right]=root;
        check(root->left,target,parent);
        check(root->right,target,parent);
    }
    void solve(TreeNode* root,int k,vector<int> &ans,unordered_map<TreeNode*,TreeNode*> &parent,unordered_map<TreeNode*,int> &m,int h){
        if(root==NULL){
            return;
        }
        if(m.find(root)!=m.end()){
            return;
        }
        m[root]=h+1;
        if(h==k){
            ans.push_back(root->val);
        }
        solve(root->left,k,ans,parent,m,h+1);
        solve(root->right,k,ans,parent,m,h+1);
        solve(parent[root],k,ans,parent,m,m[root]);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,int> m;
        vector<int> ans;
        check(root,target,parent);
        if(root==NULL || flag==false){
            return ans;
        }
        solve(target,k,ans,parent,m,0);
        return ans;
    }

};
