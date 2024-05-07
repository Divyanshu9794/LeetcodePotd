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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->val);
        l1=l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->val);
        l2=l2->next;
    }
    int carry=0;
    ListNode* result=NULL;
    while(s1.empty()==false || s2.empty()==false){
        int a=0,b=0;
        if(s1.empty()==false){
            a=s1.top();s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();s2.pop();
        }
        int total=a+b+carry;
        ListNode* temp=new ListNode();
        temp->val=total%10;
        carry=total/10;
        if(result==NULL){
            result=temp;
        }else{
            temp->next=result;
            result=temp;
        }
    }
    if(carry!=0){
        ListNode* temp=new ListNode();
        temp->val=carry;
        temp->next=result;
        result=temp;
    }
    return result;
}
 
    ListNode* doubleIt(ListNode* head) {
        ListNode* h1=head;
        ListNode* h2=head;
        return addTwoNumbers(h1,h2);
        
    }
};