#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int> arr{10,20,30};
    cout<<"Size: "<<arr.size()<<endl;
    cout<<"Capacity: "<<arr.capacity()<<endl;
    cout<<"Is Empty? "<<arr.empty()<<endl;
    arr.push_back(40);
    cout<<"Size: "<<arr.size()<<endl;
    cout<<"Capacity: "<<arr.capacity()<<endl;
    arr.pop_back();
    cout<<"Size: "<<arr.size()<<endl;
    cout<<"Capacity: "<<arr.capacity()<<endl;
    cout<<"Last Value: "<<arr.back()<<endl;
    cout<<"First Value: "<<arr.front()<<endl;
}