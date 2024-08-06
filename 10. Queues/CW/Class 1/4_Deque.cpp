#include<iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void pushRear(int data){
            // Queue is full
            // Single element case -> First element
            // Circular Nature
            // Normal flow
            
            if((front == 0 && rear == size-1) || rear == front-1){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1){
                front = 0, rear = 0;
            }
            else if(rear == size-1 && front != 0 && front != -1){
                rear = 0;
            }
            else{
                rear++;
            }
                arr[rear] = data;
        }

        void pushFront(int data){
            if((front == 0 && rear == size-1)){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front == -1)
                front = rear = 0;
            else if(front == 0 && rear != size-1){
                front = size-1;
            }
            else{
                front--;
            }
            arr[front] = -1;
        }

        void popFront(){
            
        }
};

int main(){

}