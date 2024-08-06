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

bool searchTargetFromBST(Node* root, int target){
    // bc
    if(root == NULL)
        return false;

    if(root->data == target)
        return true;

    // bool leftAns = false;
    // bool rightAns = false;
    //* Processing conditions
    if(target > root->data)
        // rightAns = searchTargetFromBST(root->right, target);
        return searchTargetFromBST(root->right, target);
    else
        // leftAns = searchTargetFromBST(root->left, target);
        return searchTargetFromBST(root->left, target);


    // return leftAns || rightAns;
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for the nodes (end with -1): " << endl;
    takeInput(root);
    // cout<<"\nPrinting Level order traversal: "<<endl;
    // levelOrderTraversal(root);
    int target = 21;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    bool ans = searchTargetFromBST(root, target);
    cout<<"Present or not: "<<ans<<endl; 
    
    // TC1: 10 20 5 11 17 2 4 8 6 25 15 -1

    // TC2: 100 150 200 175 -1
}
