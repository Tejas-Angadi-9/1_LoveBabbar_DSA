#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> arr, int n, int i){
    //base case
    if(i >= n)
        return;

    // recursive call
    reverseArray(arr, n, i+1);

    // processing
    cout<<arr[i]<<" ";
}

int main(){
    vector<int> arr {10, 20, 30, 40, 50};
    int n = arr.size();
    cout<<"Printing array right to left"<<endl;
    reverseArray(arr, n, 0);
}