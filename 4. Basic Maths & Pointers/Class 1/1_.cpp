#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 5;
    // Prints the value of 'a'
    cout<<"Value of 'a': "<<a<<endl;
    // prints the address of 'a'
    cout<<"Address of 'a': "<<&a<<endl;

    // initializing a pointer
    int *p = &a;
    // prints the address of 'a' variable from 'p' pointer
    cout<<"Address present as value in 'p': "<<p<<endl;
    // prints the value of 'a' varaiable from 'p' pointer
    cout<<"value of 'a' varaiable from 'p' pointer: "<<*p<<endl;
    // prints the address of 'p' pointer
    cout<<"address of 'p' pointer: "<<&p<<endl;

    //! BAD PRACTICE
    // int *ptr;
    // cout<<&ptr<<endl;

    //! NULL POINTER
    int *ptr = 0;
    cout<<ptr<<endl;    // Generates Segmentation Fault
    cout<<&ptr<<endl;   // Address of ptr pointer
    cout<<*ptr<<endl;   // Value present in ptr pointer
}