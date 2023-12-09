// USING 2 NESTED FOR LOOPS
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j])
                return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr {3,1,3,4,2};
    cout<<"Duplicate Number: "<<findDuplicate(arr)<<endl;
}