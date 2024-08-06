//! We will find the middle and reverse the LL after from mid+1. Create temp1 & temp2. After start comparing both halves, if equal move both the pointers forward and if not equal then return false

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

Node* findMid(Node* first){
    // Use slow and fast pointer
    Node* slow = first;
    Node* fast = first;

    while(fast != NULL && fast->next != NULL){
        fast = fast -> next;
        if(fast != NULL && fast->next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
}

Node* reverseLL(Node* &first){
    Node* prev = NULL;
    Node* curr = first;
    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node* first){

    //* EDGE CASES
    if(first == NULL){
        cout<<"LL is empty"<<endl;
        return true;
    }

    if(first->next == NULL){
        // Only one node is present and the LL is palindrome
        return true;
    }

    //* Find the middle
    Node* middleNode = findMid(first);
    //* Reverse the LL after middle node
    //! middleNode->next = reverseLL(middleNode->next);  --> WE can also do like this
    Node* secondHalfLL = reverseLL(middleNode->next);
    // cout<<"mid + 1 after reversing the LL: "<<middleNode->next->data<<endl;
    //* Create a temp1 ptr at first
    Node* temp1 = first;
    //* Create a temp12 ptr at mid+1
    // Node* temp2 = middleNode->next;      //! Check the red comment. Use it for that
    Node* temp2 = secondHalfLL;      

    //* Iterate the LL and check if it is palindrome or not
    while(temp2 != NULL){
        // cout<<"Temp1: "<<temp1->data<<" Temp2: "<<temp2->data<<endl;
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main(){
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(3);
    Node* fifth = new Node(2);
    Node* sixth = new Node(1);

    // Connecting nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = nullptr;

    cout<<isPalindrome(first)<<endl;
}