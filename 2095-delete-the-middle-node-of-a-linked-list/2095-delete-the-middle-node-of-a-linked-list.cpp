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
    
    // methods to solve the given problem
    // 1. slow & fast pointers
    // 2. find the size of the linkelist and then the middle node
    ListNode* deleteMiddle(ListNode* head) {
        
        int sz = 0;
        ListNode *curr = head,*dummy = new ListNode(-1),*prev;
        while(curr!=NULL)
        {
            sz++;
            curr = curr->next;
        }
        
        dummy->next = head;
        head = dummy;
        prev = head, curr = head->next;
        int nodeToDel = sz/2 ;
        int i=0;
        
        while(i<=nodeToDel)
        {
            if(i==nodeToDel)
            {
                prev->next = curr->next;
                curr->next = NULL;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        return head->next;
        
    }
};