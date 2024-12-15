#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>> adjList;

class Graph{
    public:

    void addEdge(int u, int v, bool direction){
        adjList[u].push_back(v);

        if(direction == 0)
            adjList[v].push_back(u);
    }

    void printAdjList(){
        for(auto node : adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second){
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                //* If it is visited and not parent is not same from the parent map then cycle is present
                if(visited[neighbour] && frontNode != parent[neighbour]){ 
                    // Cycle is present
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g;
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    g.printAdjList();

    bool ans = false;
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = g.checkCyclicUsingBFS(i, visited);
            if(ans == true)
                break;
        }
    }   


    ans == true ? cout<<"Cycle is Present"<<endl : cout<<"Cycle is not Present"<<endl;

}