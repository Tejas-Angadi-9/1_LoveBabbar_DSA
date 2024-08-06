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

int maxDepth(Node* root){
    //bc
    if(root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return (1+max(leftHeight, rightHeight));
}

int main(){
    Node* root = NULL;
    root = buildTree();
    int ans = maxDepth(root);
    cout<<"Max Depth: "<<ans<<endl;
}