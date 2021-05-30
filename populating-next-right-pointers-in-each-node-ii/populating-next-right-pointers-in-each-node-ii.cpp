/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* parent=root;
        Node* child=NULL;
        Node* childhead=NULL;
        
        while(parent!=NULL){
            while(parent!=NULL){
            if(parent->left){
                if(childhead==NULL){
                    childhead=parent->left;
                    
                }
                else{
                    child->next=parent->left;
                }
                child=parent->left;
            }
             if(parent->right){
                if(childhead==NULL){
                    childhead=parent->right;
                    
                }
                else{
                    child->next=parent->right;
                }
                child=parent->right;
            }
            parent=parent->next;
        }
        parent=childhead;
        childhead=child=NULL;
        }
        return root;
    }
};