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
    ListNode* rotateRight(ListNode* head, int k) {
     if(!head || k==0)
     {
         return head;
     }
       int c=0;
       ListNode* temp=head;
       while(temp)
       {
           c++;
           temp=temp->next;
       }

       int z=k%c;
    
       while(z--)
       {
           ListNode* curr=head;
           while(curr->next->next)
           {
               
               curr=curr->next;
           }
            ListNode* next=curr->next;
           curr->next=next->next;
           next->next=head;
           head=next;

       }
        return head;
    }
};