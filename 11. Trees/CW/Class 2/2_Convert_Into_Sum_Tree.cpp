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

int convertIntoSumTree(Node* root){
    //bc
    if(root == nullptr)
        return NULL;

    //left side call
    int leftAns = convertIntoSumTree(root->left);
    //right side call
    int rightAns = convertIntoSumTree(root->right);
    //Changing the current node
    root->data = leftAns + root->data + rightAns;
    //Return root node data
    return root->data;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    int sum = convertIntoSumTree(root);
    cout<<"Sum of the tree: "<<sum<<endl;
}