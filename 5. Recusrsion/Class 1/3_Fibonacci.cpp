#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    // if(n == 0)  return 0;
    // if(n == 1)  return 1;

    // Base Case
    if(n == 0 || n == 1) 
        return n;

    // RR
    int ans = fibo(n-1) + fibo(n-2);
    return ans;
}

int main(){
    int n = 1;
    int ans = fibo(n);
    cout<<"Last value at "<< n <<" fibonacci is: "<<ans;
}