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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        
        ListNode *curr,*prev;
        prev = head, curr = head->next;
        
        while(curr!=NULL)
        {
            if(curr->val == val)
            {
                ListNode* next = curr->next;
                prev->next = next;
                curr->next = NULL;
                curr = next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head->next;
    }
};