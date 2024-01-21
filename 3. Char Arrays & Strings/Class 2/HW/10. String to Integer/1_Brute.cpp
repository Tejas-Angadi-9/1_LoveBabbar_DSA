#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s){
    int Integer = atoi(s.c_str());
    return Integer;
}

int main(){
    string s = "  -123Hello456";
    int ans = myAtoi(s);
    cout<<ans<<endl;
}