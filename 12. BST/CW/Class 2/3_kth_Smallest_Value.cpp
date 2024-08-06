#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

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
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int findKthSmallestHelper(Node* root, int& k) {
    if (root == NULL)
        return -1;

    // Search in the left subtree
    int leftAns = findKthSmallestHelper(root->left, k);
    if (leftAns != -1)
        return leftAns;

    // Decrement k and check if the current node is the kth smallest
    k--;
    if (k == 0)
        return root->data;

    // Search in the right subtree
    // int rightAns = findKthSmallestHelper(root->right, k);
    // return rightAns;
    return findKthSmallestHelper(root->right, k);
}

int findKthSmallest(Node* root, int k){
    return findKthSmallestHelper(root, k);
}

int main() {
    Node* root = NULL;
    cout << "Enter the nodes for BST and end with -1" << endl;
    takeInput(root);
    int k = 2;
    int kthSmallest = findKthSmallest(root, k);
    cout << "Kth Smallest element: " << kthSmallest << endl;
    return 0;
}
