// Find a pair that upon addition gives value equal to the sum from the given array
#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int> arr, int n, int sum){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == sum){
                cout<<"Pair Found: " << arr[i]<<","<<arr[j]<<endl;
            }
        }
    }
}

int main(){
    vector<int> arr {1,3,5,7};
    int n = arr.size();
    int sum = 8;
    pairSum(arr, n, sum);
}

// TC: O(n^2)   SC: O(1)