#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateBy90(vector<vector<int>> &matrix){
    int n = matrix.size();

    // Transposing
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reversing each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> ans = rotateBy90(matrix);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans.size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}