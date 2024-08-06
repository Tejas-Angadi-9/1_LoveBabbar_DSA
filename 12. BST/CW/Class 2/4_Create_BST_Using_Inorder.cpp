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

void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // Here we will perform 4 steps until the queue is empty
    while (!q.empty()) {
        // A
        Node* temp = q.front();
        // B
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // C
            cout << temp->data << " ";

            // D
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}


Node* BSTUsingInorder(int inorder[], int s, int e){
    if(s > e)   
        return nullptr;

    int mid = s+(e-s)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = BSTUsingInorder(inorder, s, mid-1);
    root->right = BSTUsingInorder(inorder, mid+1, e);
    return root;
}

int main() {
    int inorder[] = {10,20,30,40,50,60,70,80};
    int s = 0, e = 7;
    Node* root = BSTUsingInorder(inorder, s, e);
    levelOrderTraversal(root);
}
