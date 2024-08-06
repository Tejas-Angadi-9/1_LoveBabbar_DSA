//TODO: fix this

// Approach 2 -> Pyara approach with no replacement of the data
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
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
 
Node* sortNodes(Node* head){
    // EDGE CASES
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    // Create 3 dummy nodes
    Node* zeroKaHead = new Node(-1);
    Node* zeroKaTail = zeroKaHead;
    Node* oneKaHead = new Node(-1);
    Node* oneKaTail = oneKaHead;
    Node* twoKaHead = new Node(-1);
    Node* twoKaTail = twoKaHead;
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            // Isolating a node from the given LL
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the zero to zeroKaHead LL
            zeroKaTail->next = temp;
            zeroKaTail = temp;
        }
        else if(curr->data == 1){
            // Isolating a node from the given LL
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the zero to zeroKaHead LL
            oneKaTail->next = temp;
            oneKaTail = temp;
        }
        else{
            // Isolating a node from the given LL
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            // Append the zero to zeroKaHead LL
            twoKaTail->next = temp;
            twoKaTail = temp;
        }
    }
    // Moving all the 3 pointers forward and deleting the dummy nodes
    Node* temp1 = zeroKaHead;
    zeroKaHead = zeroKaHead->next;
    temp1->next = NULL;
    delete temp1;
    Node* temp2 = oneKaHead;
    oneKaHead = oneKaHead->next;
    temp2->next = NULL;
    delete temp2;
    Node* temp3 = twoKaHead;
    twoKaHead = twoKaHead->next;
    temp3->next = NULL;
    delete temp3;
    // Connecting the 3 LLs
    // zeroKaHead = zeroKaHead->next;
    zeroKaTail->next = oneKaHead->next;
    oneKaTail->next = twoKaHead->next;
    return zeroKaHead;
}
 
int main(){
    Node* first = new Node(2);
    Node* second = new Node(1);
    Node* third = new Node(1);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* seventh = new Node(1);
    first->next = second;
    second->next = third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=nullptr;
    cout<<"Before sorting:"<<endl;
    print(first);
    cout<<"After sorting:"<<endl;
    first = sortNodes(first);
    print(first);
}