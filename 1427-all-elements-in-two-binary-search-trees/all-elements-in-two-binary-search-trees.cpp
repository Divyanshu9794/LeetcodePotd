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
    // void inorder(TreeNode* root,vector<int>&ans){
    //     if(root==NULL) return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    vector<int> merge(TreeNode *root1, TreeNode *root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        
        while (root1 || root2 || !s1.empty() || !s2.empty()) {
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                s2.push(root2);
                root2 = root2->left;
            }
            
            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                root1 = s1.top();
                s1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            } 
            else {
                root2 = s2.top();
                s2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // vector<int> ans;
        // if(root1==NULL && root2==NULL){
        //     return {};
        // }
        // inorder(root1,ans);
        // inorder(root2,ans);
        // sort(ans.begin(),ans.end());
        // return ans;
        return merge(root1,root2);
    }
};