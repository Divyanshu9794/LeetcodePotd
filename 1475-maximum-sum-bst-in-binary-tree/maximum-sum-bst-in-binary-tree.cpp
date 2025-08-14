class Solution {
public:
    struct NodeVal {
        int minNode, maxNode, sum;
        bool isBST;
        NodeVal(int minN, int maxN, int s, bool bst)
            : minNode(minN), maxNode(maxN), sum(s), isBST(bst) {}
    };

    int maxSum = 0;

    NodeVal helper(TreeNode* root) {
        if (!root)
            return NodeVal(INT_MAX, INT_MIN, 0, true);

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.isBST && right.isBST &&
            left.maxNode < root->val && root->val < right.minNode) {
            
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);

            return NodeVal(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum,
                true
            );
        }

        return NodeVal(INT_MIN, INT_MAX, 0, false);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
