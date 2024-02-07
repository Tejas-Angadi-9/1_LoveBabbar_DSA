#include<bits/stdc++.h>
using namespace std;

void solve(int *p){
    p += 1;
}

int main(){
    int a = 5;
    int *p = &a;
    cout<<p<<endl;
    cout<<*p<<endl;
    solve(p);
    cout<<p<<endl;
    cout<<*p<<endl;
}