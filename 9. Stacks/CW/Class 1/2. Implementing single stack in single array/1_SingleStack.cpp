#include<bits/stdc++.h>
using namespace std;
 
class Stack{
  public:
    int topIndex;
    int* arr;
    int size;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        topIndex = -1;
    }
    // Functions
    void push(int data){
        // Check if the stack is full or not
        if(size - topIndex > 1){
            // Stack space is available to insert
            topIndex++;
            arr[topIndex] = data;
        }
        else{
            // Stack is full
            cout<<"Stack is full so cannot insert the data. Stack overflow"<<endl;
        }
    }
    void pop(){
        if(topIndex != -1)
            topIndex--;
        else
            cout<<"Stack underflow. Cannot pop the data"<<endl;
    }
    int getTop(){
        if(topIndex == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[topIndex];
    }
    int getSize(){
        return topIndex+1;
    }
    bool isEmpty(){
        if(topIndex == -1)
            return true;
        else
            return false;
    }
};
 
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    if(s.isEmpty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;
    cout<<"The no. of elements present in the stack: "<<s.getSize()<<endl;
    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    if(s.isEmpty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;
 
}