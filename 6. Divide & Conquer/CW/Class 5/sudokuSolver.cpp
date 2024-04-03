//! NEED TO SOLVE THIS
#include<bits/stdc++.h>
using namespace std;

int board[9][9] = {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0},
};

bool isSafe(int value, int board[][9], int curr_row, int curr_col){
    // Row Check ie. row remains same just column changes as it goes right ->->->->
    for(int col = 0; col<9; col++){
        if(board[curr_row][col] == value){
            return false;
        }
    }
    // Col Check ie. col remains same just row changes as it goes down 
    for(int row = 0; row<9; row++){
        if(board[row][curr_col] == value)
            return false;
    }

    // 3x3 box -> We go till 9 because this 3x3 has 9 boxes 
    for(int i=0; i<9; i++){
        //TODO: We will look how this formula works?
        if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i%3)] == value){
            return false;
        }
    }
    return true;
}

//* This function returns true/false basis on we found the solution or not
bool solve(int board[][9], int n){
    //* Here we don't required base case
    // We want to fill all the empty cell ie. 0 with 1-9
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //Check is the cell empty?
            if(board[i][j] == 0){
                // We have 1-9 numbers to filled. So we will use for loop
                for(int value=1; value<=9; value++){
                    // Check is it safe to insert this value in the board or not
                    if(isSafe(value, board, i, j)){
                        // Insert
                        board[i][j] = value;
                        // rc -> One box is filled so rest will be handled by recursion
                        bool nextSolution = solve(board, n);
                        // By this above statement. We get true if we can solve further or false if we can't solve further
                        //* If we can find the solution we don't have to find the solution with another value. So instead of checking everything we return true.
                        if(nextSolution == true){   //! Because of this we don't required base case
                            return true;
                        }else{
                            //* If not then backtrack
                            board[i][j] = 0;
                        }
                    }
                }
                //* If we are not able to put any value from 1-9 in this cell then return false. That we can't put any value inside this. Backtrack is already done 

                //! Agar 1 se 9 tak koi solution nai nikla current cell par, that means piche kahi na kahi par galti hai -> Go back by returning false
                return false;
            }
        }
    }
    //* We will reach here when all the cells are filled and we don't have anything to fill so we return true
    return true;
}

int main(){
    

    int n = 9;
    solve(board, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}