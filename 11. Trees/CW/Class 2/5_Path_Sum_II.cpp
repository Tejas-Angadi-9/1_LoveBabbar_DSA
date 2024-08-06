//TODO: There is another method to solve this problem using vector method. Do check it out!!!
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

Node* buildTree(){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    // bc
    if(data <= -1){
        return NULL;
    }

    // Step A, B and C
    Node* root = new Node(data);

    cout<<"Enter the data for the left part of "<<data<<" node"<<endl;
    root->left = buildTree();
    cout<<"Enter the data for the right part of "<<data<<" node"<<endl;
    root->right = buildTree();

    return root;   
} 

void solve(Node* root, int targetSum, int currSum, vector<int> path, vector<vector<int>> &ans){
    //bc
    if(root==nullptr)
        return;

    //leafnode
    if(root->left == nullptr && root->right == nullptr){
        //Include the current leaf node in vector and add it's value in currentSum
        path.push_back(root->data);
        currSum += root->data;
        //Checking if leaf node is equal to targetSum
        if(currSum == targetSum){
            ans.push_back(path);
        }
        /* if path is passed by reference then add these steps before return
        path.pop_back();
        currSum -= root->data;
        return; 
        
        */
        return;
    }
    // Solving 1 case -> This doesn't include any operation related to leaf node
    path.push_back(root->data);
    currSum += root->data;

    // Calling left & right side from the root node
    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);
    /* if path is passed by reference then add these steps before return
    path.pop_back();
    currSum -= root->data;
    */
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    int targetSum = 22; 
    vector<vector<int>> ans = pathSum(root, targetSum);
}