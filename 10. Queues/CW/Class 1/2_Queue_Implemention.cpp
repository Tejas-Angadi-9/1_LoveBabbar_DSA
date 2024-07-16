#include<iostream>
#include<vector>
using namespace std;

class Queue{
    public:
        int size;
        int front;
        int rear;
        int *arr;
        

        Queue(int size){
            arr = new int[size];
            this->size = size;
            front = 0;
            rear = 0;
        }

        // METHODS
        //* PUSH
        void push(int data){
            // Check if the queue is empty
            if(rear == size){
                cout<<"Queue is full"<<endl;
            }
            else{
                // Queue is not empty
                arr[rear] = data;
                rear++;
            }
        }

        //* POP
        void pop(){
            //* Check if the queue is empty?
            if(front == rear)
                cout<<"Queue is empty"<<endl;
            else{
                arr[front] = -1;
                front++;

                if(front == rear){
                    front = 0;
                    rear = 0;
                }
            }
        }

        //* Get Front value
        int getFront(){
            //* Queue Empty?
            if(front == rear)
                cout<<"Queue is empty";
            else
                return arr[front];
        }

        //* Check Queue isEmpty?
        bool isEmpty(){
            if(front == rear)
                return true;
            else
                return false;
        }

        //* Get size
        int getSize(){
            return rear - front;
        }
};

int main(){
    Queue q(5);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(11);

    cout<<"Front value: "<<q.getFront()<<endl;
    cout<<"Size: "<<q.getSize()<<endl;
    q.pop();
    cout<<"Is Empty: "<<q.isEmpty()<<endl;
    cout<<"Front value: "<<q.getFront()<<endl;
    cout<<"Size: "<<q.getSize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"Size: "<<q.getSize()<<endl;
}