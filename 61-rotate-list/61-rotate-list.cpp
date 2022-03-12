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
        
        if(head==NULL || k==0) return head;
        
        int sz = 0;
        ListNode *curr = head,*list2,*prev;
        while(curr!=NULL)
        {
            sz++;
            curr = curr->next;
        }
        
        k%= sz;
        if(k==0) return head;
        int n = sz-k;
        
        int i=1;
        curr = head;
        while(i<=n)
        {
            if(i==n)
            {
                list2 = curr->next;
                curr->next = NULL;
                break;
            }
            i++;
            curr = curr->next;
        }
        
        curr = list2->next,prev=list2;
        while(curr!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = head;
        head = list2;
        return head; 
    }
};