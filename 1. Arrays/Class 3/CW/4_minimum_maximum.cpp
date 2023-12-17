#include<bits/stdc++.h>
using namespace std;

int findMinimum(int arr[][3]){
    int mini = INT_MAX;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] < mini)
                mini = arr[i][j];
        }
    }
    return mini;
}

int findMaximum(int arr[][3]){
    int maxi = INT_MIN;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] > maxi)
                maxi = arr[i][j];
        }
    }
    return maxi;
}

int main(){
    int arr[3][3] ={
        {5,6,9},
        {7,1,2},
        {4,3,12}
    };

    cout<<"Minimum: "<<findMinimum(arr)<<endl;
    cout<<"Maximum: "<<findMaximum(arr)<<endl;
}

// TC: O(n^2)   SC: O(1)