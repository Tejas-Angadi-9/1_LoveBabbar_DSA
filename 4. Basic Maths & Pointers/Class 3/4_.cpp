#include<bits/stdc++.h>
using namespace std;

void solve(int **ptr){
    ptr += 1;
}

int main(){
    int x = 12;
    int *p = &x;
    cout<<x<<endl;
    cout<<p<<endl;
    int **q = &p;
    solve(q);
    cout<<x<<endl;
    cout<<p<<endl;
}