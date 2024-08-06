#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

    if(data == -1)
        return NULL;

    Node* root = new Node(data);
    cout<<"Enter the left data to the node "<<root->data<<endl;
    root->left = buildTree();
    cout<<"Enter the right data to the node "<<root->data<<endl;
    root->right = buildTree();

    return root;
}

void printLeftView(Node* root){
    if(root == NULL)
        return;

    map<int, int> leftView;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> tempNode = q.front();
        q.pop();
        Node* firstNode = tempNode.first;
        int vd = tempNode.second;

        if(leftView.find(vd) == leftView.end()){
            // Create a new entry
            leftView[vd] = firstNode->data;
        }

        if(firstNode->left)
            q.push(make_pair(firstNode->left, vd+1));

        if(firstNode->right)
            q.push(make_pair(firstNode->right, vd+1));
    }

    for(auto it:leftView){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

void printRightView(Node* root){
    if(root == NULL)
        return;

    map<int, int> rightView;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> tempNode = q.front();
        q.pop();
        Node* firstNode = tempNode.first;
        int vd = tempNode.second;

        rightView[vd] = firstNode->data;

        if(firstNode->left)
            q.push(make_pair(firstNode->left, vd+1));

        if(firstNode->right)
            q.push(make_pair(firstNode->right, vd+1));
    }

    for(auto it:rightView){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

void printLeftTreeUsingVector(Node* root, vector<int> &ans, int level){
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

    //left part
    printLeftTreeUsingVector(root->left, ans, level+1);
    //right part
    printLeftTreeUsingVector(root->right, ans, level+1);
}

void printRightTreeUsingVector(Node* root, vector<int> &ans, int level){
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

    //right part
    printRightTreeUsingVector(root->right, ans, level+1);
    //left part
    printRightTreeUsingVector(root->left, ans, level+1);
}


int main(){
    Node* root = NULL;
    root = buildTree();
    vector<int> ans;
    int startLevel = 0;
    cout<<"Printing left view values: "<<endl;
    // printLeftView(root);
    // printLeftTreeUsingVector(root, ans, startLevel);
    printRightTreeUsingVector(root, ans, startLevel);
    for(int i:ans){
        cout<<i<<endl;
    }
    // cout<<"Printing right view values: "<<endl;
    // printRightView(root);
}

// 10 20 30 -1 -1 40 60 -1 -1 80 -1 90 -1 -1 50 -1 70 -1 -1