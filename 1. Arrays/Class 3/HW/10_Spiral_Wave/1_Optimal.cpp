#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix){
    vector<int>ans;
    int n = matrix.size();
    int m = matrix[0].size();

    int count = 0;
    int tne = m * n;

    int startingRow = 0, startingCol = 0, endingCol = m-1, endingRow = n-1;

    while(count < tne){
        for(int i=startingCol; i<=endingCol && count<tne; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for(int i=startingRow; i<=endingRow && count<tne; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for(int i=endingCol; i>=startingCol && count<tne; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for(int i=endingRow; i>=startingRow && count<tne; i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int> ans = spiralOrder(matrix);
    for(auto it:ans)
        cout<<it<<" ";
}