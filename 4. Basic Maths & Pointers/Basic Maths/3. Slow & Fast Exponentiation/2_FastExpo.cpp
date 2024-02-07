#include<bits/stdc++.h>
using namespace std;

int slowExpo(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){  // checking if b is odd. Using Bit operator
            // If b is odd
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;    //Right shifting by 1. i.e dividing 'b' by 2
    }
    return ans;
}

int main(){
    int a = 2, b = 10;
    int ans = slowExpo(a, b);
    cout<<"Ans: "<<ans<<endl;
}