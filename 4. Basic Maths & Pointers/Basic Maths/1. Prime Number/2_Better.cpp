#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1)  return false;
    int sqrtN = sqrt(n);

    for(int i=2; i<=sqrtN; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(isPrime(i))
            cnt++;
    }
    return cnt;
}

int main(){
    int n = 10;
    int ans = countPrimes(n);
    cout<<"Number of primes: "<<ans<<endl;
}