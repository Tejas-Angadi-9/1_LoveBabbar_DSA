#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int n, int k){
    // bc
    if(n == 1)
        return k;       // If only one fence is there, then we can paint all the 3 different colors. Like R,G,B

    if(n == 2)
        return (k + k * (k-1));     // For painting 2 fences, we get this expression. Look from the table -> At n=1, in diff -> we get k combos and in same upper right diagonal ie. when n=2, we still have value as k. But for diff we have k - 1 combos for n=2. So when you include all these expressions. We get k+k*(k-1) = k+k^2-k => k ^ 2 as k and k cancel out.
    
    int ans = (solveUsingRecursion(n-2, k) + solveUsingRecursion(n-1, k)) * (k-1); 
    return ans;
}

int solveUsingMemo(int n, int k, vector<int> &dp){
    if(n == 1)
        return k;       

    if(n == 2)
        return (k + k * (k-1));

    if(dp[n] != -1)
        return dp[n];

    dp[n] = (solveUsingMemo(n-2, k, dp) + solveUsingMemo(n-1, k, dp)) * (k-1); 
    return dp[n];
}

int solveUsingTab(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = (k + k * (k-1));
    
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1);
    }
    return dp[n];
}

// As this the current is only dependent on the last 2 boxes ie. indicies. After finding the ans we update the positions.
int spaceOpt(int n, int k){
    int prev2 = k;
    int prev1 = (k + k * (k-1));

    int curr;
    for(int i=3; i<=n; i++){
        curr = (prev2 + prev1) * (k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 4;
    int k = 3;

    // int ans = solveUsingRecursion(n, k);
    vector<int> dp(n+1, -1);
    // int ans = solveUsingMemo(n, k, dp);
    // int ans = solveUsingTab(n, k);
    int ans = spaceOpt(n, k);
    cout<<ans<<endl;
}