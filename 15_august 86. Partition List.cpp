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
    ListNode* partition(ListNode* head, int x) {
        vector<int> lesser;
        vector<int> greater;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                greater.push_back(temp->val);
            }

            else{
                lesser.push_back(temp->val);
            }
            temp = temp->next;
        }

        for(int i=0; i<lesser.size(); i++){
            greater.push_back(lesser[i]);
        }

        ListNode *ans = head;
        int ind = 0;
        while(ans != NULL){
            ans->val = greater[ind];
            ind++;
            ans = ans->next;
        }

        return head;
    }
};
