#include<bits/stdc++.h>
using namespace std;

int findFirstRepeatingNumber(vector<int> arr){
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
    vector<int> arr {6,10,5,4,9,12,4,10};
    cout<<"First Repeating Number: "<<findFirstRepeatingNumber(arr)<<endl;
}

// TC: O(n^2)   SC: O(1)