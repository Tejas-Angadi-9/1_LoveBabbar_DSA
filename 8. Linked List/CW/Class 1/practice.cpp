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
        ~Node(){
            cout<<"Node with value "<<this->data<<" is deleted"<<endl;
        }
};

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

//! INSERT AT HEAD
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

//! INSERT AT TAIL
void insertAtTail(Node* &head, Node* &tail, int data){
    // If the LL is empty ie head & tail is empty
    if(tail == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the LL is not empty
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLength(Node* head){
    int len = 0;
    while(head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

//! INSERT AT POSITION
void insertAtPosition(int data, int position, Node* &head, Node* &tail){
    if(position == 0){
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if(position == len){
        insertAtTail(head, tail, data);
        return;
    }
    else if(position > len){
        cout<<"Enter a valid position to insert"<<endl;
        return;
    }
    // If the LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the LL is not empty
    Node* prev = head;
    int i = 0;
    while(i < position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}

//! DELETE AT POSITION
void deleteAtPosition(int position, Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"LL is empty. Can't delete"<<endl;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    if(position == len){
        int i = 1;
        Node* prev = head;
        while(i < position-1){
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp = tail;
        tail = prev;
        delete temp;
        return;
    }

    // Deleting the middle node
    int i = 1;
    Node* prev = head;
    while(i < position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    print(head);
    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 200);
    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    int len = findLength(head);
    insertAtPosition(45,len,head,tail);
    len = findLength(head);
    print(head);
    cout<<"\nLength: "<<len<<endl;

    deleteAtPosition(4, head, tail);
    print(head);
}   