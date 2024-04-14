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
    // IF the LL is empty ie head & tail is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If LL is not empty
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

Node* reverseLL(Node* &prev, Node* &curr){
    // BC
    if(curr == NULL){
        return prev;
    }

    // Solve one case
    Node* forward = curr->next;
    curr->next = prev;

    // rc
    return reverseLL(curr, forward);
}

void print(Node* &head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    Node* prev = NULL;
    Node* curr = head;

    print(head);
    cout<<endl;
    head = reverseLL(prev, curr);
    print(head);
    cout<<endl;
}