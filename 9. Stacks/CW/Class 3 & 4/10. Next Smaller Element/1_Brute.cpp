#include<bits/stdc++.h>
using namespace std;

void findNextSmaller(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int minValue = arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j] < minValue){
                minValue = arr[j];
                break;
            }
        }
        if(minValue == arr[i])
            arr[i] = -1;
        else
            arr[i] = minValue;
    }
}

void print(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr {4,8,5,2,25};
    print(arr);
    findNextSmaller(arr);
    print(arr);
}