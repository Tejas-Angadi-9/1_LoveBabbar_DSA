#include<iostream>
#include<queue>
using namespace std;
int main(){
    //* Creation
    queue<int> q;

    //* Insertion
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(11);

    //* Size
    cout<<"Queue size: "<<q.size()<<endl;

    //* Removal
    q.pop();
    cout<<"Queue size: "<<q.size()<<endl;

    //* isEmpty
    if(q.empty())
        cout<<"Queue is empty"<<endl;
    else    
        cout<<"Queue is not empty"<<endl;

    //* Front
    cout<<"Front value: "<<q.front()<<endl;
}