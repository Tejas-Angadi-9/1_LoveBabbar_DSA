#include<bits/stdc++.h>
using namespace std;

void countZerosOnes(int arr[], int n){
    int numZero = 0, numOne = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) numZero++;
        else if(arr[i] == 1)    numOne++;
    }
    cout<<"Zeros: "<<numZero<<endl;
    cout<<"Ones: "<<numOne<<endl;
}

int main(){
    int arr[] = {0,0,1,0,1,1,1,0,0};
    int n = 9;
    countZerosOnes(arr, n);
}

// TC: O(n)     SC: O(1)