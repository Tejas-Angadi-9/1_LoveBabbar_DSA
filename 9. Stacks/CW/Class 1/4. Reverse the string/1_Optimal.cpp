#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "tejas";
    stack<char> s;
    for(auto it: str){
        s.push(it);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}