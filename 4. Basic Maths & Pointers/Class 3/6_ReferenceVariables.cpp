#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 5;
    int &b = a;

    cout<<a<<" "<<b<<endl;

    a++;

    cout<<a<<" "<<b<<endl;
    
    b++;

    cout<<a<<" "<<b<<endl;
}