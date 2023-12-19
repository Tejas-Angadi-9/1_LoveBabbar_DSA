#include<bits/stdc++.h>
using namespace std;

int findSquareRoot(int n){
    int s = 0, e = n, ans = -1;
    int mid = s+(e-s)/2;
    while(s <= e){
        int sq = mid * mid;
        if(sq == n) return mid;
        else if(sq > n) e = mid - 1;
        else{
            ans = mid;
            s = mid + 1;
        }   

        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    int n = 11;
    int ans = findSquareRoot(n);
    cout<<"Square Root: "<<ans<<endl;
}

// TC: O(logN)  SC: O(1)