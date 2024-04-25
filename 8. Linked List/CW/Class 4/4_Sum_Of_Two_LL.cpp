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

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* solve(Node* &head1, Node* &head2){
    // Reverse both the LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    // Addition logic
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    //* How to add -> Use pointers
    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1->data + head2->data;
        int digit = sum % 10;
        carry = sum/10;
        // Put this digit in the newNode
        Node* newNode = new Node(digit);
        if(ansHead == NULL){
            // This is the first node so assign this newNode to ansHead and ansTail
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            // This means that it is not the first node as some nodes are already present
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        // Connect this newNode to the ans but check if the ans LL is empty or not
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }

    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        // Connect this newNode to the ans but check if the ans LL is empty or not
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    // If carry is present
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // Reverse the ans and return the node
    Node* ans = reverseLL(ansHead);
    return ans;
}

int main(){
    Node* head1 = new Node(9);
    Node* second1 = new Node(9);
    head1->next = second1;

    Node* head2 = new Node(9);
    Node* second2 = new Node(9);
    Node* third2 = new Node(9);
    head2->next = second2;
    second2->next = third2;

    Node* ans = solve(head1, head2);
    print(ans);
}