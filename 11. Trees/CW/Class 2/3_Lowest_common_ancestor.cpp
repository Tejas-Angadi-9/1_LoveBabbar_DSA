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

Node* findLCA(Node* root, Node* p, Node* q){
    //bc
    if(root == nullptr)
        return nullptr;

    //Check for p and q
    if(root->data == p->data)
        return p;
    if(root->data == q->data)
        return q;

    // Go to left & right subtree
    Node* leftAns = findLCA(root->left, p, q);
    Node* rightAns = findLCA(root->right, p, q);

    // Check for all 4 conditions / possibilities
    if(leftAns == NULL && rightAns == NULL)
        return nullptr;
    else if(leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if(leftAns == NULL && rightAns != NULL)
        return rightAns;
    else    
        return root;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    // TODO: p, q, call FindLCA Function
}