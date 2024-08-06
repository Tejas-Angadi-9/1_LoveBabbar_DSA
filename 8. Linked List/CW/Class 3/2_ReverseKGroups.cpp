//! USING FAST AND SLOW POINTERS
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int findLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

Node* reverseKNodes(Node* head, int k){
    // LL is empty
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }

    // If k is greater than the LL length
    int len = findLength(head);
    if(k > len || k < 0){
        return head;
    }

    // Nodes in LL is >= k
    // STEP A: reverse first k nodes of LL
    // Here we will first create 3 pointers -> prev, curr and forward
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    
    // STEP B: Recursive call
    if(forward != NULL){
        // We still have nodes to reverse so the result should be connected to the head->next
        head->next = reverseKNodes(forward, k);      // Now leave the first k nodes. The forward is the head for the next nodes
    }

    // STEP C: Return the head of the modified LL
    return prev;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout<<"\nAfter reversing k nodes"<<endl;
    head = reverseKNodes(head, 3);
    print(head);
    cout<<endl;

}

// TC: O(n)