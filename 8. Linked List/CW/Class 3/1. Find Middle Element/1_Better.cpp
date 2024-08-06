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

int getMiddleElement(Node* head, int position){
    Node* curr = head;
    int i = 1;
    while(i < position){
        curr = curr->next;
        i++;
    }
    return curr->data;
}

int findMiddleElement(Node* head){
    // If the LL is empty
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return -1;
    }

    // LL is not empty
    //* STEPS:
    // 1. Find the total length of the LL
    int length = findLength(head);
    // 2. Check if the Length is even or odd
    // 3. If even then return the mid value
    if(length % 2 == 0){
        return getMiddleElement(head, length/2);
        
    }
    // 4. If odd then return the mid+1 value 
    else{
        return getMiddleElement(head, length/2 + 1);
    }
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
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    print(head);
    cout<<"Middle Element: "<<findMiddleElement(head)<<endl;
}

// TC: O(n) + O(n) = O(n)