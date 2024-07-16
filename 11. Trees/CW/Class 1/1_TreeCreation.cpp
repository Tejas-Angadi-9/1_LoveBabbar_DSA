#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* buildTree(){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    // bc
    if(data <= -1){
        return NULL;
    }

    // Step A, B and C
    Node* root = new Node(data);

    cout<<"Enter the data for the left part of "<<data<<" node"<<endl;
    root->left = buildTree();
    cout<<"Enter the data for the right part of "<<data<<" node"<<endl;
    root->right = buildTree();

    return root;   
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    // Here we will perform 4 steps until the queue is empty
    while(!q.empty()){
        // A
        Node* temp = q.front();
        // B
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // C
            cout<<temp->data<<" ";

            // D
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    // Here we will perform 4 steps until the queue is empty
    while(!q.empty()){
        // A
        Node* temp = q.front();
        // B
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // C
            cout<<temp->data<<" ";

            // D
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }
}

void preOrderTraversal(Node* root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL)
        return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    root = buildTree();
    cout<<"Printing from left to right"<<endl;
    levelOrderTraversal(root);
    cout<<"\nPrinting from right to left"<<endl;
    reverseLevelOrderTraversal(root);
    cout<<"\nPrinting Pre-Order Traversal"<<endl;
    preOrderTraversal(root);
    cout<<"\nPrinting In-Order Traversal"<<endl;
    inOrderTraversal(root);
    cout<<"\nPrinting Post-Order Traversal"<<endl;
    postOrderTraversal(root);
}