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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> q;
        queue<TreeNode *> que;
        que.push(root);
        while(que.size()){
            long long sum=0;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode *x = que.front();
                if(x->left) que.push(x->left);
                if(x->right) que.push(x->right);
                sum += x->val;
                que.pop();
            }
            q.push(sum);
        }
        if(q.size()<(k)) return -1;
        while(k-->1) q.pop();
        return q.top();
    }
};