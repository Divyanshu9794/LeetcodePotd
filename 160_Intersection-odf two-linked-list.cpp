/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        int lenA = 0, lenB = 0;
		ListNode* tempA = headA, *tempB = headB;
		while (tempA){ ++lenA; tempA = tempA->next; }
		while (tempB){ ++lenB; tempB = tempB->next; }
		int n = lenA >= lenB ? (lenA - lenB) : (lenB - lenA);
		tempA = lenA >= lenB ? headA : headB;
		tempB = lenA >= lenB ? headB : headA;
		while (tempA){
			tempA = tempA->next;
			if ((n--) <= 0)	tempB = tempB->next;
			if (tempA == tempB)
				return tempA;
		}
		return nullptr;
    }
};