// Sort 0's 1's 2's -> COUNTING APPROACH #1
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
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == 0)
            zeroCount++;
        else if(curr->data == 1)
            oneCount++;
        else
            twoCount++;
        curr = curr->next;
    }
    curr = head;
    // Inserting these values in the LL
    while(curr != NULL){
        while(zeroCount--){
            curr->data = 0;
            curr = curr->next;
        }
        while(oneCount--){
            curr->data = 1;
            curr = curr->next;
        }
        while(twoCount--){
            curr->data = 2;
            curr = curr->next;
        }
    }
    return head;
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
 
// TC: O(n) + O(n) = O(n)       SC: O(1)