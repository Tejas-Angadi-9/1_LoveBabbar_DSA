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

void preOrder(Node* root){
    // NLR
    if(root == NULL)
        return;

    // N
    cout<<root->data<<" ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}
void inOrder(Node* root){
    // LNR
    if(root == NULL)
        return;

    // L
    inOrder(root->left);
    // N
    cout<<root->data<<" ";
    // R
    inOrder(root->right);
}
void postOrder(Node* root){
    // NLR
    if(root == NULL)
        return;

    // L
    postOrder(root->left);
    // R
    postOrder(root->right);
    // N
    cout<<root->data<<" ";
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for the nodes (end with -1): " << endl;
    takeInput(root);
    cout<<"\nPrinting Level order traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<"\nPrinting Pre-order traversal: "<<endl;
    preOrder(root);
    cout<<"\nPrinting In-order traversal: "<<endl;
    inOrder(root);
    cout<<"\nPrinting Post-order traversal: "<<endl;
    postOrder(root);

    return 0;
}
