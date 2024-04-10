#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // IF the head is null then the new node to be created will be the head and tail 
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //! If we don't pass by reference we move the head pointer in the function but acutally we don't have the head pointer changed in the acutal LL pointing at it. We also use pass by reference to avoid returning the value
    // STEPS
    // 1. Create a new node
    Node* newNode = new Node(data);
    // 2. Connect the new node's next to head
    newNode->next = head;
    // 3. Move the head pointer back to the newNode
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        // IF the head is null then the new node to be created will be the head and tail 
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void print(Node* head){
    Node* temp = head;
    // Run the while loop until temp ie head is not null
    while(temp != NULL){
        // Print the data from the temp's node
        cout<<temp->data<<" ";
        // Move the temp pointer forward
        temp = temp->next;
    }
}

int main(){
    //* If head is null
    // Node* head = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    insertAtTail(head, tail, 99);
    insertAtTail(head, tail, 200);
    print(head);
}