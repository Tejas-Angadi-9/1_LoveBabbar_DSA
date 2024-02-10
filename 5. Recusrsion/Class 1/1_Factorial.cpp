#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    // Base Case
    if(n == 1)    return 1; 

    // Recursive call
    return n * factorial(n-1);
}

int main(){
    int n = 4;

    int ans = factorial(n);
    cout<<"Factorial of "<<n<<" is: "<<ans<<endl;
}