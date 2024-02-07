#include<bits/stdc++.h>
using namespace std;

int slowExpo(int a, int b){
    int ans = 1;
    for(int i=0; i<b; i++){
        ans *= a;
    }
    return ans;
}

int main(){
    int a = 2, b = 10;
    int ans = slowExpo(a, b);
    cout<<"Ans: "<<ans<<endl;
}