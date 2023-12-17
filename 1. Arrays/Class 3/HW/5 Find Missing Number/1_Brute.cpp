#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> arr){
    int n = arr.size();
    int hash[n+1] = {0};

    for(int i=0; i<n-1; i++){
        hash[arr[i]]++;
    }

    for(int i=1; i<=n; i++){
        if(hash[i] == 0)
            return i;
    }
    return -1;
}

int main(){
    vector<int> arr {1,2,3,4,6};
    cout<<"Missing Number: "<<findMissingNumber(arr)<<endl;
}