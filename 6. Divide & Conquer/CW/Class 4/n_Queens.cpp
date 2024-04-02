#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>> board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> board, int n){
    // Check can we keep the queen in the current cell or not
    //! Here we will check the left part not the right part to place the queens. As previous will let us know that can we place the queen in the current position (i, j) or not
    //* As right part is empty. There is no need to check it so that we an place the queen there
    int i = row, j = col;

    // Check row
    while(j >= 0){
        if(board[i][j] == 'Q')
            return false;
        j--;
    }

    // Check upper left diagonal
    //* Before doing this set the row and col to i & j respectively. As it might have get changed
    i = row, j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--, j--;
    }

    // Check bottom left diagonal
    i = row, j = col;
    while(i<n && j>=0){
        if(board[i][j] == 'Q')
            return false;
        i++, j--;
    }

    // Even after these computations. We don't find a queen then return true
    return true;
}

void solve(vector<vector<char>> board, int n, int col){
    // Base case
    if(col >= n){   //! -> We can use == instead of >= but we will use this as this is much safer 
        //Print the solution
        printSolution(board, n);
        return;
    }

    // Solve 1 case reset will be handled by recursion
    // Current col is 0 so we will try to place queen 1 in every row
    for(int row = 0; row<n; row++){
        // Check is it safe to place the queen in particular row and column?
        if(isSafe(row, col, board, n)){
            // Keep
            //* 0 means empty cell and 1 means queen is present
            board[row][col] = 'Q';
            // Solution will be bought by recursion. So we need to go the next col
            solve(board, n, col+1);
            // Backtracing -> Remove queen ie. 1 to 0
            board[row][col] = '-';
        }
    }
}

int main(){
    int n = 4;
    vector<vector<char>> board (n, vector<char> (n,'-'));
    int col = 0;
    solve(board, n, col);
}