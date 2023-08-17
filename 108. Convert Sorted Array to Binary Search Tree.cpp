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
    TreeNode* buildbst(vector<int>& nums,int left, int right) {
        if(left>right){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* newno = new TreeNode(nums[mid]);
        newno->left = buildbst(nums,left,mid-1);
        newno->right = buildbst(nums,mid+1,right);
        return newno;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
           return buildbst(nums,0,nums.size()-1);
    }
};
