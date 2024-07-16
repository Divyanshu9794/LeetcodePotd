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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca_node = lca(root, startValue, destValue);
        string start = "";
        string end = "";
        dfs(lca_node, startValue, start);
        dfs(lca_node, destValue, end);
        string start_path(start.size(), 'U');
        return start_path + end;
    }
bool dfs(TreeNode* root, int value, string& path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == value) {
            return true;
        }

        if (root->left) {
            path += "L";
            if (dfs(root->left, value, path)) {
                return true;
            }
            path.pop_back(); // Backtrack if left path doesn't lead to value
        }

        if (root->right) {
            path += "R";
            if (dfs(root->right, value, path)) {
                return true;
            }
            path.pop_back(); // Backtrack if right path doesn't lead to value
        }

        return false;
    }

TreeNode *lca(TreeNode *root, int s, int t)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->val == s || root->val == t)
    {
        return root;
    }
    TreeNode *left = lca(root->left, s, t);
    TreeNode *right = lca(root->right, s, t);
    if (left != nullptr && right != nullptr)
    {
        return root;
    }
    return left != nullptr ? left : right;
}

};