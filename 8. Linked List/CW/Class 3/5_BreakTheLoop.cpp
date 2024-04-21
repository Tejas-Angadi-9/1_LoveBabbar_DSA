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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool checkIsCircular(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow)    return true;
    }
    return false;
}

void breakLoop(Node* head){
    if(head == NULL || head->next == NULL){
        cout<<"LL is empty"<<endl;
        return ;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            slow = head;
            break;
        }
    }

    // Step C:
    Node* prev = fast;
    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
}

int main(){
    Node* first = new Node(50);
    Node* second = new Node(40);
    Node* third = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    bool ans = checkIsCircular(first);
    cout<<"Is the loop circular: "<<ans<<endl;
    breakLoop(first);
    ans = checkIsCircular(first);
    cout<<"Is the loop circular: "<<ans<<endl;
}