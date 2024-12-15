#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction){
        // Directed means it's 1 and undirected means it's 0
        adjList[u].push_back({v, wt});
        if(direction == 1){
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

    //* This method gives the topological order in DFS.
    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans){
        visited[src] = true;

        for(auto neighbour : adjList[src]){
            if(!visited[neighbour.first]){
                topoSortDfs(neighbour.first, visited, ans);
            }
        }

        ans.push(src);
    }

    void shortestPathDfs(int dest, stack<int> &topoOrder, int n){
        //* Creating a dist array of n size and assigning all the values as INT_MAX 
        vector<int> dist(n, INT_MAX);

        //* Initial steps, getting the top value, popping and marking distance as 0
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        //* Getting all the neighbours of src
        for(auto nbr : adjList[0]){
            // Update all the distance of the neigbours
            // Current weight + edge Weight < neigbour's node present in the array then update. 
            if(dist[0] +  nbr.second < dist[nbr.first]){
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while(!topoOrder.empty()){
            int topElement = topoOrder.top();
            topoOrder.pop();


            //! Checking if the distance is valid
            //* When the current value is INT_MAX and we have a weight of 5 so we can't store INT_MAX + 5 
            if(dist[topElement] != INT_MAX){
                //* Getting all the neighbours
                for(auto nbr : adjList[topElement]){
                    // Update all the distance of the neigbours
                    // Current weight + edge Weight < weight present in the array then update. 
                    if(dist[topElement] +  nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }
        cout<<"Printing Ans: "<<endl;
        for(int i=0; i<n; i++){
            cout<<i<<"-> "<<dist[i]<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,5,0);
    g.addEdge(0,2,3,0);
    g.addEdge(2,1,2,0);

    g.addEdge(1,3,3,0);
    g.addEdge(2,3,5,0);
    g.addEdge(2,4,6,0);
     
    g.addEdge(4,3,1,0);

    cout<<"Printing Adj list: "<<endl;
    g.printAdjList();

    stack<int> topoOrder;
    unordered_map<int, bool>  visited;
    g.topoSortDfs(0, visited, topoOrder);

    //* Now fill the distance array
    int dest = 3;
    int noOfNodes = 5;
    g.shortestPathDfs(dest, topoOrder, noOfNodes);
}