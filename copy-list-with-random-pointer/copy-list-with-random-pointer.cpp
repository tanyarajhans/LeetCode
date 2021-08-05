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
        if(head==NULL)
            return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            Node* nex=temp->next;
            temp->next=copy;
            copy->next=nex;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL)
                temp->next->random=temp->random->next;
            else
                temp->next->random=NULL;
            temp=temp->next->next;
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