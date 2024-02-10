#include<bits/stdc++.h>
using namespace std;

void ascendingCount(int n){
    // BASE CASE
    if(n == 0)
        return;

    // recursive call
    ascendingCount(n-1);

    // processing
    cout<<n<<" ";
}

void desendingCount(int n){

    // BASE CASE
    if(n == 0)
        return;

    // processing
    cout<<n<<" ";

    // recursive call
    desendingCount(n-1);
}

int main(){
    int n = 10;
    ascendingCount(n);
    cout<<endl;
    desendingCount(n);
}