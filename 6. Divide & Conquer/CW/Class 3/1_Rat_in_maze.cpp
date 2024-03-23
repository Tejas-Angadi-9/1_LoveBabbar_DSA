#include<bits/stdc++.h>
using namespace std;

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output){
    // base case
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return ;
    }

    //* We will solve for 1 case. Rest will be handled by the recursion
    // DOWN ->  (i+1, j)
    // LEFT ->  (i, j-1)
    // RIGHT -> (i, j+1)
    // UP ->    (i-1, j)
}

int main(){
    int maze[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1},
    };

    int row = 3, col = 3;

    // Create a visited matrix with all the values set to false
    vector<vector<bool>>visited (row, vector<bool>(col, false));
    // Initially we start from (0,0). So set the visited(0,0) from false to true
    visited[0][0] = true;

    // Vector string to store the path like DLRU -> (Down, Left, Right, Up) 
    vector<string> path;
    string output = "";

    // Call the function
    //* Source of the rat's starting position from 0,0 indices
    int i = 0, j = 0;
    solveMaze(maze, row, col, i, j, visited, path, output);
}