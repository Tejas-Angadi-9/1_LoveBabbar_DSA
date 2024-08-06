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

void storeInorder(Node* root, vector<int> &inorder){
    //bc
    if(root == NULL)
        return;

    // L
    storeInorder(root->left, inorder);
    // N
    inorder.push_back(root->data);
    // R
    storeInorder(root->right, inorder);
}

bool findTarget(Node* root, int target){
    vector<int> inorder;
    storeInorder(root, inorder);
    int i = 0, j = inorder.size()-1;
    while(i<=j){
        int sum = inorder[i] + inorder[j];
        if(sum == target){
            return true;
        }
        else if(sum > target)
            j--;
        else
            i++;
    }
    return false;
}

int main() {
    Node* root = NULL;
    cout << "Enter the nodes for BST and end with -1" << endl;
    takeInput(root);
    int target = 320;
    bool isTargetFound = findTarget(root, target);
    cout << "Is target found: " << (isTargetFound ? "Yes found" : "Not found")<< endl;
    return 0;
}
