#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr, int n){
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j])
                cnt++;
        }

        if(cnt > n/2)
            return arr[i];
    }
    return -1;
}

int main(){
    vector<int> arr {2,2,1,1,1,2,2};
    int n = arr.size();

    cout<<"Majority Element: "<<majorityElement(arr, n)<<endl;
}