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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *curr,*prev,*dummy=new ListNode(-1),*prev1,*prev2;
        dummy->next = head;
        head = dummy;
        curr = head->next, prev = head;
        
        for(int i=1;i<=left;i++)
        {
            if(i<left)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev1 = curr;
                prev2 = prev;
                while(i<=right)
                {
                    ListNode *next = curr->next;
                    curr->next = prev;
                    prev= curr;
                    curr = next;
                    i++;
                }
                
                prev1->next = curr;
                prev2->next = prev;
                
                break;
                
            }
        }
        
        return head->next;
        
    }
};