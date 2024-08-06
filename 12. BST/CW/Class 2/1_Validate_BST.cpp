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

Node* buildBST(Node* root, int data){
    //bc
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = buildBST(root->right, data);
    }
    else{
        root->left = buildBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

bool solve(Node* root, int lowerBound, int upperBound){
    //bc
    if(root == NULL)    
        return true;

    if(root->data > lowerBound && root->data < upperBound){
        bool leftAns = solve(root->left, lowerBound, root->data);
        bool rightAns = solve(root->right, root->data, upperBound);
        return leftAns && rightAns;
    }
    else{
        return false;
    }
}

bool isValidBST(Node* root){
    int lowerBound = INT_MIN;
    int upperBound = INT_MAX;
    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

int main(){
    Node* root = NULL;
    cout << "Enter the data for the nodes (end with -1): " << endl;
    takeInput(root);
    bool ans = isValidBST(root);
    cout<<"Valid: "<<ans<<endl;
}