#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n, int i){
    //base case
    if(i >= n)
        return;

    // processing
    cout<<arr[i]<<" ";

    // recursive call
    printArray(arr, n, i+1);
}


int main(){
    vector<int> arr {10, 20, 30, 40, 50};
    int n = arr.size();
    cout<<"Printing array left to right"<<endl;
    printArray(arr, n, 0);
}