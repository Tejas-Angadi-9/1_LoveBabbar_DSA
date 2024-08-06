#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void queueInterleaving(queue<int> &q){
    int n = q.size();
    queue<int> q1;
    queue<int> q2;

    for(int i=0; i<n/2; i++){
        int value = q.front();
        q.pop();
        q1.push(value);
    }

    for(int i=n/2; i<n; i++){
        int value = q.front();
        q.pop();
        q2.push(value);
    }

    while(!q1.empty() && !q2.empty()){
        int q1Value = q1.front();
        q1.pop();
        q.push(q1Value);
        int q2Value = q2.front();
        q2.pop(); 
        q.push(q2Value);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    cout<<"Queue before interleaving"<<endl;
    print(q);
    cout<<"Queue after interleaving"<<endl;
    queueInterleaving(q);
    print(q);
}