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

Node* getStartingPointLoop(Node* head){
    if(head == NULL || head->next == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
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
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    if(ans){
        Node* startingPoint = getStartingPointLoop(first);
        cout<<"Starting point: "<<startingPoint->data<<endl;
    }
    else{
        cout<<"There is no starting point as the LL is not circular"<<endl;
    }
}