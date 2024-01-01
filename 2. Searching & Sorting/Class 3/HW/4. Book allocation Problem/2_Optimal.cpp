#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid){
    int students = 1, totalPages = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > mid)    return false;
        if(totalPages + arr[i] > mid){
            students++;
            totalPages = arr[i];
            if(students > m)    return false; 
        }else{
            totalPages += arr[i];
        }
    }
    return true;
}

int bookAllocation(vector<int> arr, int n, int m){
    int sum = 0, ans = -1;
    for(int i=0; i<n; i++)
        sum+=arr[i];
    int s=0, e=sum;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }else   
            s = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> arr {10,20,30,40};
    int n=4, m=2;
    int ans = bookAllocation(arr, n, m);
    cout<<ans<<endl;
}