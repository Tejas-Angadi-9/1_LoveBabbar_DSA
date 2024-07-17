//TODO: There is another method to solve this problem using vector method. Do check it out!!!
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

bool kthAncestor(Node* root, int k, int p){
    // bc
    if(root == nullptr)
        return false;

    if(root->data == p)
        return true;

    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);
    if(leftAns || rightAns)
        k--;

    if(k == 0){
        cout<<"Answer: "<<root->data<<endl;
        k = -1;         // Important step to do, if we don't then it will print other values with k = 0
    }
    return leftAns || rightAns;     // Return true if any one condition is true
}   

int main(){
    Node* root = NULL;
    root = buildTree();
    int k = 2, p = 7;       // p always exists in the tree
    bool ans = kthAncestor(root, k, p);
}