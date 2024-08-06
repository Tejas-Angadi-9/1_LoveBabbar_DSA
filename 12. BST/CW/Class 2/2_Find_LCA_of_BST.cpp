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

Node* findLCA(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    // If both p and q are greater than root, LCA lies in right
    if (root->data < p && root->data < q) {
        root->right = findLCA(root->right, p, q);
    }
    // If both p and q are smaller than root, LCA lies in left
    if (root->data > p && root->data > q) {
        root->left = findLCA(root->left, p, q);
    }
    
    // If p and q are on different sides of root, then root is LCA
    return root;
}

int main() {
    Node* root = NULL;
    cout << "Enter the nodes for BST and end with -1" << endl;
    takeInput(root);
    int p = 70, q = 160;
    Node* LCA_root = findLCA(root, p, q);
    if (LCA_root != NULL)
        cout << "LCA: " << LCA_root->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
