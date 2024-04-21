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


int findMiddleElement(Node* head){
    Node* slow = head;
    Node* fast = head; 
    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(slow != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // else if(fast->next == NULL)  break;      // Optional -> Use it when condition is not used in while loop
    }
    return slow->data;
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
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout<<endl;
    cout<<"Middle Element: "<<findMiddleElement(head)<<endl;
}

// TC: O(n)     SC: O(1)