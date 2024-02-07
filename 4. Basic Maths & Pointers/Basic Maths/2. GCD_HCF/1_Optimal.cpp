#include<bits/stdc++.h>
using namespace std;

int gcd(int A, int B){
    if(A == 0)  return A;
    if(B == 0)  return B;

    while(A > 0 && B > 0){
        if(A > B)
            A = A - B;
        else
            B = B - A;
    }
    return A == 0 ? B : A;
}

int lcm(int A, int B, int gcd){
    return (A * B)/gcd;
}

int main(){
    int a = 24, b = 72;
    int gcdAns = gcd(a, b);
    cout<<"GCD: "<<gcdAns<<endl;
    cout<<"LCM: "<<lcm(a, b, gcdAns)<<endl;
}