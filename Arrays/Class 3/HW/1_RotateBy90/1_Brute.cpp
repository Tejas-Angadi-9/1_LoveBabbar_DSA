#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> arr){
    for(int i=0; i<3; i++){
        for(int j=2; j>=0; j--){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> arr {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotateMatrix(arr);
}