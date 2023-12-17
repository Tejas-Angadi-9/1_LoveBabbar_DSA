#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> arr){
    int xor1 = 0, xor2 = 0, n=arr.size();
    for(int i=1; i<=n; i++){
        xor1 = xor1 ^ arr[i-1];
        xor2 = xor2 ^ i;
    }
    return xor1 ^ xor2;
}

int main(){
    vector<int> arr {1,2,4,5};
    cout<<"Missing Number: "<<findMissingNumber(arr)<<endl;
}