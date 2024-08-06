#include<bits/stdc++.h>
using namespace std;

void findMiddleElement(stack<int> &s, int n){

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
        return;
    }

    // BC
    if(n % 2 == 0){
        if(s.size() == n/2){
            cout<<"Middle element is: "<<s.top()<<endl;
            return;
        }
    }else{
        if(s.size() == n/2+1){
            cout<<"Middle element is: "<<s.top()<<endl;
            return;
        }
    }

    

    //One case solve
    int temp = s.top();
    s.pop();

    //rc
    findMiddleElement(s, n);

    // Backtrack -> Insert the values back
    s.push(temp);
}

int main(){ 
    stack<int> s;

    s.push(10);    
    s.push(20);    
    s.push(30);    
    s.push(40);    
    // s.push(50);    
    // s.push(60);    
    // s.push(70);   
    // s.push(80);   

    int n = s.size();
    findMiddleElement(s, n);
}