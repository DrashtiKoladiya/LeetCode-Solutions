/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return NULL;
        
        Node *curr = head,*curr1;
        
        while(curr!=NULL)
        {
            Node *new_node = new Node(curr->val);
            Node *next = curr->next;
            
            new_node->next = next;
            curr->next = new_node;
            
            curr = next;
        }
        
        curr = head;
        while(curr!=NULL)
        {
            if(curr->random!=NULL) curr->next->random = curr->random->next;
            
            curr = curr->next->next;
        }
        
        Node *dummy = new Node(-1);
        curr = dummy;
        curr1 = head;
        while(curr1!=NULL)
        {
            curr->next = curr1->next;
            curr = curr->next;
            
            curr1->next = curr1->next->next;
            curr1 = curr1->next;
        }
        
        return dummy->next;
        
    }
};