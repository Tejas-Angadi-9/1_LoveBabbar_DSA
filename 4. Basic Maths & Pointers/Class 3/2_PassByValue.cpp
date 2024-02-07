#include<bits/stdc++.h>
using namespace std;

void util(int *p){
    p += 1;
}

int main(){
    int a = 5;
    int *p = &a;
    cout<<"Before"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    util(&a);

    cout<<"After"<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
}