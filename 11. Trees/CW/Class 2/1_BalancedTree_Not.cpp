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

int findHeight(Node* root){
    //bc
    if(root == NULL)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (1+max(leftHeight, rightHeight));
}

bool isBalanced(Node* root){
    // bc
    if(root == nullptr)
        return true;

    // Solve 1 case
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    int diff = abs(leftHeight - rightHeight);
    bool ans1 = (diff <= 1);            // It stores true if the diff <= 1 else false

    // Rest nodes will be handled by recursion
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    return ans1 && leftAns && rightAns;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    bool ans = isBalanced(root);
    if(ans)
        cout<<"Tree is balanced in each node"<<endl;
    else    
        cout<<"Tree is not balanced in each node"<<endl;
}