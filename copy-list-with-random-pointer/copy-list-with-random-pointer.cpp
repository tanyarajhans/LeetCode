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
        if (head == NULL) 
            return NULL;
        Node* curr = head;
        Node* temp;
        while(curr!=NULL){
            temp=curr->next;
            Node* t=new Node(curr->val);
            curr->next=t;
            t->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr){
             if(curr->random)
                curr->next->random = curr->random->next;
             curr=curr->next->next;
        }
        Node* og=head;
        Node* copyHead=head->next;
        
        while(og){
            Node* next=og->next->next;
            Node* copy=og->next;
            og->next=next;
            if(next!=NULL)
                copy->next=next->next;
            og=next;
        }
        
        return copyHead;
    }
};