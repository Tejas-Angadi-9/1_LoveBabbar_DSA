#include<iostream>
#include<map>
#include<queue>
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

void printBottomView(Node* root){
    if(root == nullptr)
        return;

    map<int, int> topNode;

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout<<"Printing the bottom view of the tree"<<endl;
    for(auto it:topNode){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

void printTopView(Node* root){
    if(root == nullptr)
        return;

    map<int, int> topNode;

    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout<<"Printing the top view of the tree"<<endl;
    for(auto it:topNode){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree();
    printTopView(root);
    printBottomView(root);
}

// 10 20 30 -1 -1 40 60 -1 -1 70 -1 -1 50 -1 90 80 -1 -1 100 -1 -1

// 1 2 3 -1 -1 5 6 -1 -1 -1 4 7 -1 9 -1 -1 8 -1 -1