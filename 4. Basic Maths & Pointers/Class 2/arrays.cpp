#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;
    cout<<arr<<endl;
    cout<<*arr+1<<endl;     // -> similar to *(arr)+1
    cout<<&arr[1]<<endl;
    cout<<*arr+2<<endl;
    cout<<*(arr)+1<<endl;
    cout<<*(arr)+100<<endl;
    cout<<*(arr+1)<<endl;

    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<i[arr]<<" ";
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<*(i+arr)<<" ";
    }
    cout<<endl;

    // Can't change the actual addresss of the array
    // arr = arr+2;
    // cout<<arr<<endl;

    // But this can be made possible using a pointer
    int *p = arr;
    cout<<p<<endl;
    p = p + 2;
    cout<<"Address of 2nd index using array: "<<&arr[2]<<endl;
    cout<<"Address of 2nd index using pointer: "<<p<<endl;
    cout<<"value of array using ptr address "<<*p<<endl;
}