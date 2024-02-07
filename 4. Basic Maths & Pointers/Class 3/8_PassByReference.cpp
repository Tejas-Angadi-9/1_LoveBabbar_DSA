#include<bits/stdc++.h>
using namespace std;

void solve(int &a){
    a++;
}

int main(){
    int a = 5;
    cout<<"Before: "<<a<<endl;
    solve(a);;
    cout<<"After: "<<a<<endl;
}