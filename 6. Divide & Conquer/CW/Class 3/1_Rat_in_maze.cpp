#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[][3], vector<vector<bool>> &visited){
    if(((i >= 0 && i<row) && (j >= 0 && j < col)) &&
        // 2nd condition checking if the maze in unblocked -> 1
        (arr[i][j] == 1) &&
        // 3rd condition checking if the way is visited already ie. -> 0/false
        (visited[i][j] == false)
        
    ){
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(int arr[3][3], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string output){
    // base case
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return ;
    }

    //* We will solve for 1 case. Rest will be handled by the recursion
    // DOWN ->  (i+1, j)
    if(isSafe(i+1, j, row, col, arr, visited)){
        // Mark the visited matrix as true
        visited[i+1][j] = true;
        // rc
        solveMaze(arr, row, col, i+1, j, visited, path, output+'D');
        // Backtrack
        visited[i+1][j] = false;
    }
    // LEFT ->  (i, j-1)
    if(isSafe(i, j-1, row, col, arr, visited)){
        // Mark the visited matrix as true
        visited[i][j-1] = true;
        // rc
        solveMaze(arr, row, col, i, j-1, visited, path, output+'L');
        // Backtrack
        visited[i][j-1] = false;
    }
    // RIGHT -> (i, j+1)
    if(isSafe(i, j+1, row, col, arr, visited)){
        // Mark the visited matrix as true
        visited[i][j+1] = true;
        // rc
        solveMaze(arr, row, col, i, j+1, visited, path, output+'R');
        // Backtrack
        visited[i][j+1] = false;
    }
    // UP ->    (i-1, j)
    if(isSafe(i-1, j, row, col, arr, visited)){
        // Mark the visited matrix as true
        visited[i-1][j] = true;
        // rc
        solveMaze(arr, row, col, i-1, j, visited, path, output+'U');
        // Backtrack
        visited[i-1][j] = false;
    }
}

int main(){
    int maze[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1},
    };

    // If src is blocked
    if(maze[0][0] == 0){
        cout<<"No paths found"<<endl;
        return 0;
    }

    int row = 3, col = 3;
    // If dest is blocked
    if(maze[row-1][col-1] == 0){
        cout<<"No paths found"<<endl;
        return 0;
    }


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

    //* Print the paths
    for(auto it: path){
        cout<<it<<" ";
    }
}