#include<iostream>
using namespace std;

class cirQueue{
  public:
    int size;
    int front;
    int rear;
    int *arr;
    
    cirQueue(int size){
        this->size = size;
        arr = new int[size];
        front=-1;
        rear = -1;
    }
    
    // METHODS
    //PUSH
    void push(int data){
        // Queue is full
        // Single element case -> First element
        // Circular Nature
        // Normal flow
        
        if((front == 0 && rear == size-1) || rear == front-1){
            cout<<"Queue is full"<<endl;
        }
        else if(front == -1){
            front = 0, rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0 && front != -1){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }
    
    //POP
    void pop(){
        //STEPS
        // Empty check
        // Single element
        // Circular element
        // Normal flow
        
        if(front == -1){
            cout<<"Q is empty, cannot pop"<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
};

int main(){
    cirQueue q(5);
    
    q.push(10);
}