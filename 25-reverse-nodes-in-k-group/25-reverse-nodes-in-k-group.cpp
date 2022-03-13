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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k<=1 || head==NULL || head->next==NULL) return head;
        
        int sz=0;
        ListNode *curr = head;
        while(curr!=NULL)
        {
            curr = curr->next;
            sz++;
        }
        
        int blocks = sz/k;
        
        ListNode *dummy = new ListNode(-1),*prev,*prev1,*prev2;
        dummy->next = head;
        head = dummy;
        
        curr = head->next;
        prev2 = head;
        
        while(blocks--)
        {
            int tmp = k;
            prev1 = curr;
            while(tmp--)
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            prev1->next = curr;
            prev2->next = prev;
            
            prev2 = prev1;   
        }
        
        return dummy->next;
        
        
        
    }
};