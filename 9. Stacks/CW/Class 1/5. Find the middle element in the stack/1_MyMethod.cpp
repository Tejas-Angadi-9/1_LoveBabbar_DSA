#include<bits/stdc++.h>
using namespace std;

int findMiddleElement(stack<int> &s, int n){
    int count = 0;
    while(count != n/2){
        s.pop();
        count++;
    }
    return s.top();
}

int main(){
    stack<int> s;

    s.push(10);    
    s.push(20);    
    s.push(30);    
    s.push(40);    
    s.push(50);    
    s.push(60);    
    s.push(70);   
    s.push(80);   

    int n = s.size();
    int ans = findMiddleElement(s, n);
    cout<<"Answer: "<<ans<<endl;
}