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


void printLeftToRight(Node* head){
    Node* temp = head;
    while(temp != NULL){        // Until current address of the temp is not null if temp->next is used then it checks if the next address of the temp is nullptr or what?
        // Print the data 
        cout<<temp->data<<' ';
        // Move the pointer forward
        temp = temp->next;
    }
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    printLeftToRight(first);
    cout<<endl;
    cout<<first->next->next->next<<endl;
}