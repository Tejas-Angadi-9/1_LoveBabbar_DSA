#include<bits/stdc++.h>
using namespace std;

void tripletSum(int arr[], int n, int sum){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == sum)
                    cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<endl;
            }
        }
    }
}

int main(){
    int arr[] = {10,20,30,40};
    int n = 4;
    int sum = 80;

    tripletSum(arr, n, sum);
}

// TC: O(n^3)   SC: O(1)