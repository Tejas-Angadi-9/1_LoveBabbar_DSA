#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

    // If it's not a first node then decide to go to left or right depending on the given data with the condition
    if (data > root->data) {
        // Go to right
        root->right = insertIntoBST(root->right, data);
    } else {  
        // Go to left
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        // Until the data is not -1 then I will create a tree
        root = insertIntoBST(root, data);
        cin >> data; // Read next data
    }
}

void findMaximum(Node* root, int &maxi){
    if(root == NULL)    return;

    if(root->data > maxi){
        maxi = root->data;
    }

    findMaximum(root->right, maxi);
    findMaximum(root->left, maxi);
}

void findMinimum(Node* root, int &mini){
    if(root == NULL)    return;

    if(root->data < mini)
        mini = root->data;

    findMinimum(root->left, mini);
    findMinimum(root->right, mini);
}

Node* findTargetNode(Node* root, int target){
    // bc
    if(root == NULL)    return NULL;

    if(target == root->data){
        if(root->left != NULL && root->right != NULL)
            return root;
    }
    if(target > root->data)
        return findTargetNode(root->right, target);
    else
        return findTargetNode(root->left, target);
}

void findPredecessorAndSuccessor(Node* root, int target){
    // Find if the target is present and then check does it have 2 children?
    // If not, then stop the execution and return the answer
    // If yes, then do the rest of the steps
        // To find the predecessor we go to the left subtree of the target node and find the maximum and return that value
        // To find the successor we go to the right subtree of the target node and find the minimum and return that value
    Node* targetNode = findTargetNode(root, target);
    if(targetNode){
        // Find the max from the left subtree
        int maxi = INT_MIN, mini = INT_MAX;
        findMaximum(targetNode, maxi);
        findMinimum(targetNode, mini);

        cout<<"Inorder Predecessor: "<<maxi<<endl;
        cout<<"Inorder Successor: "<<mini<<endl;
    }
    else{
        cout<<"Can't find Predecessor or successor as target node doesn't contain children"<<endl;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter the data for the nodes (end with -1): "<<endl;
    takeInput(root);
    int target = 5;
    findPredecessorAndSuccessor(root, target);
}