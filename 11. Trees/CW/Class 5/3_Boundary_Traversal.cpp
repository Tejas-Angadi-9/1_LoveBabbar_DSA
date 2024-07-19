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

void printLeftBoundary(Node* root){
    // bc
    if(root== NULL)
        return;

    // Return if it is leaf node
    if(root->left == NULL && root->right == NULL)
        return;
 
    // process the current node
    cout<<root->data<<" ";
    // Go to left
    if(root->left){     // if root->left exists then call or else skip and move forward
        printLeftBoundary(root->left);
    }
    // Then go right
    else{
        printLeftBoundary(root->right);
    }

}
void printLeafBoundary(Node* root){
    // bc
    if(root== NULL)
        return;

    // Return if it is leaf node
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
    // Go to left
    printLeafBoundary(root->left);
    // Then go right
    printLeafBoundary(root->right);

}
void printRightBoundary(Node* root){
    // bc
    if(root== NULL)
        return;

    // Return if it is leaf node
    if(root->left == NULL && root->right == NULL)
        return;
    
    if(root->right)
        printRightBoundary(root->right);
    else 
        printRightBoundary(root->left);
    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root){
    if(root == NULL)
        return;

    //printing the root node to avoid the duplicacy.
    cout<<root->data<<" ";

    // A -> Left most nodes not the left view (NLR)
    printLeftBoundary(root->left);
    // B -> Leaf nodes
    printLeafBoundary(root);
    // C -> Right most nodes not the right view but in reverse order
    printRightBoundary(root->right);
}

int main(){
    Node* root = NULL;
    root = buildTree();
    boundaryTraversal(root);
}

// TC1: 10 5 3 -1 -1 8 7 -1 -1 -1 20 18 -1 -1 25 -1 -1
// TC2: 10 20 40 -1 -1 50 60 -1 -1 -1 30 -1 70 -1 -1