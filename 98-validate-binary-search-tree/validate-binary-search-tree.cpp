class Solution {
public:
    bool isbst(TreeNode* root, long long minval, long long maxval) {
        if (!root) return true;

        if (root->val <= minval || root->val >= maxval)
            return false;

        return isbst(root->left, minval, root->val) &&
               isbst(root->right, root->val, maxval);
    }

    bool isValidBST(TreeNode* root) {
        return isbst(root, LLONG_MIN, LLONG_MAX);
    }
};
