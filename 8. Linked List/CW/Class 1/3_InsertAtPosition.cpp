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

int findLength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail){
    // Handling starting position
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step1: Find the position: prev & curr
    int len = findLength(head);
    if(position == len){
        insertAtTail(head, tail, data);
        return;
    }
    int i = 1; // As this is not index like an array or string. It's for us to count the number of positions
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step 2: 
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}

// TODO: Check this again.
void deleteNode(int position, Node* &head, Node* &tail){
    // If LL is empty
    if(head == NULL){
        cout<<"Cannot delete the node, LL is empty";
        return;
    }

    // Check if The position is 1 and want to delete the first node. Then
    if(position == 1){
        // Create a temp pointer
        Node* temp = head;
        // Move the head pointer forward
        head = temp->next;
        // Disconnect the first node ie. temp node to null
        temp->next = NULL;
        // Delete the temp node
        delete temp;
        return;
    }

    int len = findLength(head);
    // Invalid position
    if(position > len){
        cout<<"Position must be within the LL"<<endl;
        return;
    }

    // Check if the position of the node is at the last 
    if(position == len){
        // find prev
        int i = 1;
        Node* prev = head;
        while(i < position - 1){
            prev = prev->next;
            i++;
        }
        // Step2: 
        prev->next = NULL;
        // Step3: 
        Node* temp = tail;
        // Step4:
        tail = prev;
        // Step5:
        delete temp;
        return;
    }

    // Deleting the middle node
    int i = 1;
    Node*prev = head;
    while(i < position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    // Step2: 
    prev->next = curr->next;
    // Step3:
    curr->next = NULL;
    // Step4:
    delete curr;
    return;
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
    // cout<<"\nLength of the LL is: "<<len<<endl;
    // cout<<"HEAD: "<<head->data<<endl;
    // cout<<"TAIL: "<<tail->data<<endl;
    // print(head);

    insertAtPosition(87, 5, head, tail);
    // deleteNode(100, head, tail);
    // cout<<"HEAD: "<<head->data<<endl;
    // cout<<"TAIL: "<<tail->data<<endl;
    print(head);
    int len = findLength(head);
    cout<<"\nLength of the LL is: "<<len<<endl;
    deleteNode(3, head, tail);
    print(head);
    len = findLength(head);
    cout<<"\nLength of the LL is: "<<len<<endl;
}