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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        int r = 0;
        int i = 0;
        unordered_map<int,set<int>> m1;
        unordered_map<int,int> m2;
        while(temp){
            r += temp->val;
            v.push_back(r);
            m1[r].insert(i);
            m2[r]++;
            temp = temp->next;
            i++;
        }
        i = v.size()-1;
        vector<int> in;
        while(i>=0){
            m2[v[i]]--;
            cout<<i<<" ";
            if(v[i] == 0) break;
            else if(m2[v[i]] > 0){
                for(int x : m1[v[i]]){
                    i = x;
                    break;
                }
                m1.erase(v[i]);
                m2[v[i]] = 1;
            }
            else{
                in.push_back(i);
                m1.erase(v[i]);
                i--;
            }
        }
        i = 0;
        int j = in.size()-1;
        temp = head;
        ListNode* t = new ListNode(-1);
        ListNode* rt = t;
        while(temp){
            if(j < 0) break;
            if(i == in[j]){
                rt->next = temp;
                rt = rt->next;
                j--;
            }
            i++;
            temp = temp->next;
        }
        rt->next = NULL;
        return t->next;
    }
};