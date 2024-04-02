#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z){
    //bc
    if(n == 0)
        return 0;
    
    if(n < 0)
        return INT_MIN;

    // we go to the next rod by breaking n-x that is 1 rod. So we add + 1 to the solved the value
    int ans1 = solve(n-x, x,y,z) + 1;
    int ans2 = solve(n-y, x,y,z) + 1;
    int ans3 = solve(n-z, x,y,z) + 1;

    int ans = max(ans1, max(ans1, ans2));

    return ans;
}

int main(){
    int n = 8, x = 3, y = 3, z = 3;
    int ans = solve(n,x,y,z);
    if(ans < 0)
        ans = 0;
    cout<<ans<<endl;
}