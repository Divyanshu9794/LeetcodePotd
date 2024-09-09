/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans (m,vector<int> (n));
        for(int k=0;k<m;k++){
            fill(ans[k].begin(), ans[k].end(),-1);;
        }
        ListNode* itr = head;
        int i=0,j=0;
        int t=0,l=0,r=n-1,d=m-1;
        while(itr!=NULL){
            for(i=t,j=l;j<=r;j++){
                if(itr==NULL){
                    return ans;
                }
                ans[i][j]=itr->val;
                itr=itr->next;
            }
            t++;
            for(i=t,j=r;i<=d;i++){
                if(itr==NULL){
                    return ans;
                }
                ans[i][j]=itr->val;
                itr=itr->next;
            }
            r--;
            for(i=d,j=r;j>=l;j--){
                if(itr==NULL){
                    return ans;
                }
                ans[i][j]=itr->val;
                itr=itr->next;
            }
            d--;
            for(i=d,j=l;i>=t;i--){
                if(itr==NULL){
                    return ans;
                }
                ans[i][j]=itr->val;
                itr=itr->next;
            }
            l++;            
        }
        return ans;
    }
};