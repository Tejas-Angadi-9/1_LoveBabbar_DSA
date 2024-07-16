#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reversingFirstKElements(queue<int> &q, int k){
    int temp = k;
    // Step1: Put the first k elements in the stack
    stack<int> st;
    while(temp--){
        int value = q.front();
        q.pop();
        st.push(value);
    }

    // Step2: Put the values back to queue
    while(!st.empty()){
        int element = st.top();
        st.pop();
        q.push(element);
    }

    // Step3: Pop the n-k elements and push it in the same queue
    int n = q.size();
    int count = n - k;
    cout<<"Count: "<<k<<endl;
    while(count--){
        int value = q.front();
        q.pop();
        q.push(value);
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    int k = 3;

    cout<<"Before reversing first K elements"<<endl;
    print(q);
    reversingFirstKElements(q, k);
    print(q);

}