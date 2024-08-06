#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
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

void findMinimumValue(Node* root, int &mini){
    //! APPROACH 2: The commented part is the 2nd approach where we check for the condition and update. Also go to RIGHT part from the root
    // bc
    if(root == NULL)
        return;

    // if(root->data < mini)
        mini = root->data;

    // Call for left and right
    findMinimumValue(root->left, mini);
    // findMinimumValue(root->right, mini);
}

void findMaximumValue(Node* root, int &maxi){
    // ! APPROACH 2: The commented part is the 2nd approach where we check for the condition and update. Also go to LEFT part from the root   
    // bc
    if(root == NULL)
        return;

    // if(root->data > maxi)
        maxi = root->data;

    // Call for left and right
    findMaximumValue(root->right, maxi);
    // findMaximumValue(root->left, maxi);
}

int main() {

    //! #APPROACH 1: Store the inorder and print the first value and last value as minimum and maximum respectively.
    Node* root = NULL;
    cout << "Enter the data for the nodes (end with -1): " << endl;
    takeInput(root);
    // cout<<"\nPrinting Level order traversal: "<<endl;
    // levelOrderTraversal(root);
    int target = 21;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    findMinimumValue(root, mini);
    cout<<"Minimum value from the BST is: "<<mini<<endl;
    findMaximumValue(root, maxi);
    cout<<"Maximum value from the BST is: "<<maxi<<endl;
    // TC1: 10 20 5 11 17 2 4 8 6 25 15 -1

    // TC2: 100 150 200 175 -1
}
