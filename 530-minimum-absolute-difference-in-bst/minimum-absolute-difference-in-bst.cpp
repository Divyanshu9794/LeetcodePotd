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
    void InOrder(TreeNode* root, vector<int>& num){
        if (root == NULL) return ;
        InOrder(root->left, num);
        num.push_back(root->val);
        InOrder(root->right, num);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> num;
        InOrder(root, num);
        int s = num.size();
        int d = abs(num[1] - num[0]);
        for(int i = 2; i < s; i++){
            int dd = abs(num[i] - num[i-1]);
            if (dd < d) d = dd;
        }
        return d;
    }  
};