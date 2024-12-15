#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction){
        // Directed means it's 1 and undirected means it's 0
        adjList[u].push_back({v, wt});
        if(direction == 0){
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestPathBfs(int src, int dest){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // Handle initial things by pushing, marking and setting parent for src
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr.first]){        // As nbr is a pair of node & weight
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                }
            }
        }

        vector<int> ans;
        stack<int> st;
        int node = dest;
        for(auto it:parent){
            cout<<it.first<<"->>"<<it.second<<endl;
        }

        // Traversing the parent map which is int -> int type to store the paths from dest to src
        while(node != -1){
            ans.push_back(node);
            st.push(node);
            node = parent[node];
        }

        while(!st.empty()){
            cout<<st.top()<<",";
            st.pop();
        }

        // Then reversing the stored ans
        // reverse(ans.begin(), ans.end());
        // cout<<"Printing ans:"<<endl;
        // for(auto i:ans){
        //     cout<<i<<", ";
        // }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);

    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);
     
    g.addEdge(0,6,1,1);
    g.addEdge(6,7,1,1);
    g.addEdge(7,8,1,1);
    g.addEdge(8,4,1,1);
    cout<<"Printing Adj list: "<<endl;
    g.printAdjList();
    
    int src = 0;
    int dest = 4;

    g.shortestPathBfs(src, dest);


}