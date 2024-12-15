#include<bits/stdc++.h>
using namespace std;
template<typename T>        // dont end it with ;

class Graph{
    public:
        unordered_map<T, list<pair<T, T>>> adjList;     // T is used to have any type of datatype

        void addEgde(T u, T v, T weight, bool direction){
            // direction = 0 => Undirected Graph
            // direction = 1 => Directed Graph
            //* Ir-respective of directed or undirected Graph. 'u to v' will always form the graph
            adjList[u].push_back({v, weight});    // In 'u' inserted 'v' as neighbour.

            //* If this is undirected I need to also do it reverse.
            if(direction == 0)
                adjList[v].push_back({u, weight});
        }

        void printAdjList(){
            for(auto node:adjList){
                cout<<node.first<<" -> ";
                for(auto neighbour: node.second){
                    cout<<"{"<<neighbour.first<<", "<<neighbour.second<<"}, ";
                }
                cout<<endl;
            }
        }
};

int main(){
    // Graph g;
    // Graph<int> g;

    //* Un-directed edge input
    // g.addEgde(0, 1, 0);
    // g.addEgde(1, 2, 0);
    // g.addEgde(0, 2, 0);
    // cout<<endl;
    // g.printAdjList();

    //* Directed edge input
    // g.addEdge(srcNode, destNode, weight, direction);
    // g.addEgde(0, 1, 5, 1);
    // g.addEgde(1, 2, 8, 1);
    // g.addEgde(0, 1, 6, 1);
    // g.printAdjList();


    Graph<char> g;
    g.addEgde('a', 'b', 5, 1);
    g.addEgde('b', 'c', 8, 1);
    g.addEgde('a', 'c', 6, 1);
    g.printAdjList();


    // T n;
    // cout<<"Enter the number of nodes: "<<endl;
    // cin>>n;

    // T e;
    // cout<<"Enter the number of edges: "<<endl;
    // cin>>e;

}