#include<bits/stdc++.h>
using namespace std;

int findOddOccuringElement(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n-1; i+=2){
        if(arr[i] != arr[i+1])
            return i;
    }
    return -1;
}

int main(){
    vector<int> arr {1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = findOddOccuringElement(arr);
    cout<<"Odd occuring Index: "<<ans<<endl;
    cout<<"Odd occuring Value: "<<arr[ans]<<endl;
}