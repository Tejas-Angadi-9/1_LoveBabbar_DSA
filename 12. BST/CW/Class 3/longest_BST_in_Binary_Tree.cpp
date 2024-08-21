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

class NodeData{
    public:
        int size;
        int maxVal;
        int minVal;
        bool validBST;

    NodeData(int size, int maxi, int mini, bool valid){
        this->size = size;
        this->maxVal = maxi;
        this->minVal = mini;
        this->validBST = valid;
    }
};

NodeData* findLargestBST(Node* root, int &ans){
    // bc
    if(root == NULL){
        NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    // Get the left and right ans from the left and right subtree respectively
    NodeData* leftAns = findLargestBST(root->left, ans);
    NodeData* rightAns = findLargestBST(root->right, ans);

    // Now we got the both answers. We just need to check it. ie. logic part
    // Initialize current node's answer
    // ! Make sure you initialize first then make changes. Else it will not work properly. Ex: NodeData* currentNodeAns;
    NodeData* currNodeAns = new NodeData(0, 0, 0, false);
    // Now Checking starts here

    // Performing all the checks on the current Node
    // Storing the size from leftSubtree + rightSubtree + 1 (ie. currentNode)
    currNodeAns->size = leftAns->size + rightAns->size + 1;
    // Get the max value from the leftSubtree
    currNodeAns->maxVal = max(root->data, rightAns->maxVal);
    // Get the min value from the rightSubtree
    currNodeAns->minVal = min(root->data, leftAns->minVal);
    // Check if the left and right subtree is a valid BST or not. Along side also check if the currentNode data > leftSubtree's maxValue and currentNode data < rightSubtree's minValue
    if(leftAns->validBST && rightAns->validBST && (root->data > leftAns->maxVal && root->data < rightAns->minVal)){
        currNodeAns->validBST = true;
    }else{
        currNodeAns->validBST = false;
    }

    // As all the checks are completed. Now comes the updation of the ans variable
    // Update the ans variable only if the currentNode's Ans is a valid BST
    if(currNodeAns->validBST){
        ans = max(ans, currNodeAns->size);
    }
    return currNodeAns;
}

Node* createBst(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = createBst(root->right, data);
    }
    else{
        root->left = createBst(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = createBst(root, data);
        cin>>data;
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

int main(){
    // Node* root = NULL;
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth; 
    // cout<<"Printing the tree"<<endl;
    // levelOrderTraversal(root);

    int ans = 0;
    NodeData* findSize = findLargestBST(root, ans);
    cout<<"Largest BST size is: "<<ans<<endl;
}