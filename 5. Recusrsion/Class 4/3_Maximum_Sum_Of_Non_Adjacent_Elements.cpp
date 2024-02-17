#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int i, int sum, int &maxi){
    //bc
    if(i >= arr.size()){
        //update maxi
        maxi = max(maxi, sum);
        return ;
    }

    //include
    solve(arr, i+2, sum+arr[i], maxi);

    // exclude
    solve(arr, i+1, sum, maxi);
}

int main(){
    vector<int> arr {2,1,4,9};
    int sum = 0, maxi = INT_MIN;
    solve(arr, 0, sum, maxi);
    cout<<"Maximum sum: "<<maxi<<endl;
}