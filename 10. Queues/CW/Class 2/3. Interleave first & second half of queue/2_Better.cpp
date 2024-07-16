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

    for(int i=0; i<n/2; i++){
        int value = q.front();
        q.pop();
        q1.push(value);
    }

    while(!q1.empty()){
        int q1Value = q1.front();
        q1.pop();
        q.push(q1Value);

        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    // For odd n size
    if(n&1){
        int element = q.front();
        q.pop();
        q.push(element);
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
    // q.push(80);

    cout<<"Queue before interleaving"<<endl;
    print(q);
    cout<<"Queue after interleaving"<<endl;
    queueInterleaving(q);
    print(q);
}