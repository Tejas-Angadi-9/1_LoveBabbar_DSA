#include<bits/stdc++.h>
using namespace std;

int findQuotient(int dividend, int divisor){
    int s = 0, e = dividend, ans = -1;
    int mid = s+(e-s)/2;
    while(s<=e){
        int value = mid * divisor;
        if(value <= dividend){
            ans = mid;
            s = mid + 1;
        }else   
            e = mid - 1;
        
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    int dividend = 10, divisor = 3;
    int ans = findQuotient(dividend, divisor);
    cout<<"Quotient: "<<ans<<endl;
}

// TC: O(logn)  SC: O(1)