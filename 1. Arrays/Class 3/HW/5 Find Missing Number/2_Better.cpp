#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> arr){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n-1; i++)
        sum += arr[i];
    int totalValue = n * (n+1)/2;
    cout<<"Total Value: "<<totalValue<<endl;
    cout<<"Sum: "<<sum<<endl;
    return totalValue - sum;
}

int main(){
    vector<int> arr {1,3};

    cout<<"Missing Number: "<<findMissingNumber(arr)<<endl;
}