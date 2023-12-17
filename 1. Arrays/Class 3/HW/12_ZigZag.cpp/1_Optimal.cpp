#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> matrix){
    int n=matrix.size(), m=matrix[0].size();
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            for(int j=0; j<m; j++)
                ans.push_back(matrix[i][j]);
        }else{
            for(int j=m-1; j>=0; j--)
                ans.push_back(matrix[i][j]);
        }
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

    vector<int> ans = wavePrint(matrix);
    for(auto it:ans)
        cout<<it<<" ";
}