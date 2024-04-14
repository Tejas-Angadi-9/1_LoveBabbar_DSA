#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

//! Print function
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

//! Find length of the LL
int getLength(Node* &head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//! INSERTION AT HEAD
void insertAtHead(Node* &head, Node* &tail, int data){
    //* If the LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //* If the LL is not empty
    // Step1:
    Node* newNode = new Node(data);
    // Step2:
    newNode->next = head;
    // Step3:
    head->prev = newNode;
    // Step4:
    head = newNode;
}

//! INSERTION AT TAIL
void insertAtTail(Node* &head, Node* &tail, int data){
    //* If the LL is empty
    if(tail == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    //* If the LL is not empty
    //Step1:
    Node* newNode = new Node(data);
    //Step2:
    tail->next = newNode;
    //Step3:
    newNode->prev = tail;
    //Step4:
    tail = newNode;
}

//! INSERTION AT A POSITION
void insertionAtPosition(Node* &head, Node* &tail, int position, int data){
    // CASE1: IF THE LL IS EMPTY
    if(head == nullptr){
        insertAtHead(head, tail, data);
        return;
    }
    if(tail == NULL){
        insertAtTail(head, tail, data);
        return;
    }
    // CASE2: IF THE LL IS NOT EMPTY
    // EDGE CASE
    if(position <= 0){
        cout<<"Positioning starts from 1"<<endl;
        return;
    }
    //SUBCASE1: Insert at head
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }
    //SUBCASE2: Insert at Last position
    int len = getLength(head);
    if(position >= len){
        insertAtTail(head, tail, data);
        return;
    }
    // SUBCASE3: Insert at any other position other than head and tail
    Node* left = head;
    int i = 1;
    while(i < position-1){
        i++;
        left = left->next;
    }
    Node* right = left->next;

    // STEP1:
    Node* newNode = new Node(data);

    right->prev = newNode;
    newNode->next = right;

    left->next = newNode;
    newNode->prev = left;
}

//! DELETION OF A NODE
void deleteNode(Node* &head, Node* &tail, int position){
    //* LL is empty
    if(head == NULL){
        cout<<"LL is empty. Can't delete"<<endl;
        return;
    }

    //* LL is not empty
    // EDGE CASE
    if(position <= 0){
        cout<<"Position starts from 1 not from 0"<<endl;
        return;
    }
    //* CASE1: DELETION OF NODE AT THE 1ST POSITION
    if(position == 1){
        Node* temp = head;
        // Step1:
        head = head->next;
        // Step2:
        temp->next = NULL;
        // Step3:
        head->prev = NULL;
        // Step4:
        delete temp;
        return;
    }
    //* CASE2: DELETION OF NODE AT THE LAST POSITION
    int len = getLength(head);
    if(position >= len){
        Node* temp = tail;
        Node* left = tail->prev;
        left->next = NULL;
        tail->prev = NULL;
        tail = left;
        delete temp;
        return;
    }
    //* CASE3: DELETION OF NODE AT THE ith POSITION
    int i = 1;
    Node* left = head;
    while(i < position-1){
        i++;
        left = left->next;
    }
    // STEP1:
    Node* curr = left->next;
    // Node* right = curr->next;
    Node* right = left->next->next;
    // STEP2:
    left->next = right;
    right->prev = left;

    curr->next = NULL;
    curr->prev = NULL; 
    // We don't do reight->prev = NULL as it is already connected to left node and adding this will disconnect the node
    delete curr;
}

int main(){
    // Node* first = NULL;
    // print(first);
    // int len = getLength(first);
    // cout<<"Length: "<<len<<endl;

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);

    // // Connecting the nodes
    // first->prev = NULL;
    // first->next = second;

    // second->prev = first;
    // second->next = third;

    // third->prev = second;
    // third->next = NULL;

    // int len = getLength(first);
    // cout<<"Length: "<<len<<endl;
    // print(first);

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 90);
    insertAtTail(head, tail, 65);

    // INSERTION AT LAST POSITION
    insertionAtPosition(head, tail, 3, 100);
    int len = getLength(head);
    cout<<"Length: "<<len<<endl;
    cout<<"Head: "<<head->data<<" Tail: "<<tail->data<<endl;
    print(head);
    cout<<endl;
    len = getLength(head);
    deleteNode(head, tail, 3);
    cout<<"Length: "<<len<<endl;
    cout<<"Head: "<<head->data<<" Tail: "<<tail->data<<endl;
    print(head);
} 