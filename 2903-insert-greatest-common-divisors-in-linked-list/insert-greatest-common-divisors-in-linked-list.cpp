class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* h=head;
        while(h->next!=NULL){
            ListNode* n=h->next;
            int num=h->val;
            int num2=h->next->val;
            ListNode* h1=new ListNode(__gcd(num,num2));
            h->next = h1;
            h1->next=n;
            h=h->next->next;
        }
            return head;

    }
};