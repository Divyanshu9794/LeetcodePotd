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
int find(TreeNode* node, unordered_map<int, int> &m, int n)
{
    m[node->val]+=1;
    int ans1=0, ans2=0;
    
    if(node->left != NULL)
        ans1 = find(node->left, m, n+1);

    if(node->right != NULL)
        ans2 = find(node->right, m, n+1);

    if(node->right == NULL && node->left == NULL)
    {
        int odd=0;
        for(auto i=m.begin(); i!=m.end(); ++i)
        {
            int curr = i->second;
            if(curr%2 == 1)
                ++odd;
        }

        if(n%2 == 0 && odd == 0)
        {
            m[node->val]-=1;
            return 1;
        }

        else if(n%2 == 0 && odd != 0)
        {
            m[node->val]-=1;
            return 0;
        }

        else if(n%2 == 1 && odd == 1)
        {
            m[node->val]-=1;
            return 1;
        }

        else if(n%2 == 1 && odd == 0)
        {
            m[node->val]-=1;
            return 0;
        }
    }

    m[node->val]-=1;
    return ans1 + ans2;
}


class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int, int> m;
        return find(root, m, 1);
    }
};