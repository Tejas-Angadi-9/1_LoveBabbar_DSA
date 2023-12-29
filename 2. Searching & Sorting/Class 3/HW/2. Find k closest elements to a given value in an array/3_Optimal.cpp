#include<bits/stdc++.h>
using namespace std;

int ls(vector<int> arr, int x){
    int s = 0, e = arr.size()-1, ans = e;
    while (s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] >= x){
            ans = mid;
            e=mid-1;
        }else
            s=mid+1;
    }
    return ans;
}

vector<int> findClosestElements(vector<int> arr, int k, int x){
    int h = ls(arr, x);
    int l = h-1;

    while(k--){
        if(l == 0)  h++;
        else if(x - arr[l] > arr[h] - x)    h++;
        else    l--;
    }
    return vector<int> (arr.begin()+l+1, arr.begin()+h);
}

int main(){
    vector<int> arr {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4, x = 35;
    vector<int> ans = findClosestElements(arr, k, x);
    for(int it:ans)
        cout<<it<<" ";
}

// TC: O(logn)   O(1)