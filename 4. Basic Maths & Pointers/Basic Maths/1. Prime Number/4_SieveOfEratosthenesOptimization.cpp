//! SIEVE OF ERATOSTHENES THEOREM
#include<bits/stdc++.h>
using namespace std;

vector<bool> countPrimes(int n){
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    
    for(int i=2; i*i<=n; i++){
            if(sieve[i] == true){
            // int j = 2 * i;
            int j = i * i;

            while(j <= n){
                sieve[j] = false;
                j = j+i;
            }
        }
    }
    return sieve;
}

int main(){
    int n = 25;
    vector<bool> ans = countPrimes(n);
    // cout<<"Number of primes: "<<ans<<endl;
    for(int i=0; i<ans.size(); i++){
        if(ans[i])
            cout<<i<<" ";
    }
}

// TC: O(n(log(logn)))      SC: O(n)