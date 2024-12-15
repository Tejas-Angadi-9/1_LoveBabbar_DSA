#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    // Creation of Adjacency matrix
    vector<vector<int>> adj(n, vector<int> (n, 0));

    // Edge
    int e;
    cout<<"Enter the number of edges list length: "<<endl;
    cin>>e;

    cout<<"Enter the edges: "<<endl;
    // Taking the input for edges
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        // Marking
        adj[u][v] = 1;
    } 

    // Printing the adj matrix
    for(auto it:adj){
        for(auto val:it){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}