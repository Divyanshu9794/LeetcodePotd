class Solution {
public:
    bool dfs(ListNode* head, ListNode* cur, TreeNode* root){
        if(cur == NULL) return true;
        if(root == NULL) return false;

        if(cur->val == root->val){
            cur = cur->next;
        }
        else if(head->val == root->val){
            head = head->next;
        }
        else{
            cur = head;
        }
        return dfs(head, cur, root->left) || dfs(head, cur, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
};