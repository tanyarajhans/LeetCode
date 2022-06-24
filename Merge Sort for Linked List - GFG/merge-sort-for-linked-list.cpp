// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node* head){
        if(!head)
            return NULL;
        Node* slow=head;
        Node* fast=head->next;
        while (slow->next && (fast && fast->next)) {
        slow = slow->next;
        fast = fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* l1, Node* l2){
        if(!l1 && !l2)
            return NULL;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(l1 && l2){
            if(l1->data < l2->data){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        while(l1!=NULL){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
            
        while(l2!=NULL){
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        return dummy->next;
            
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
        return head;
        Node* mid=findMid(head);
        Node* x=mid->next;
        mid->next=NULL;
        Node* l1=mergeSort(head);
        Node* l2=mergeSort(x);
        Node* v=merge(l1,l2);
        return v;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends