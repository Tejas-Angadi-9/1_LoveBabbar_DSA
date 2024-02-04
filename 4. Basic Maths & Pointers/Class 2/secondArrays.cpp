#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[4] = {5,6,7,8};
    int *p = arr;
    int *q = arr+1;

    cout<<arr<<" "<<p<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<*(p)+1<<endl;
    cout<<*(q)+1<<endl;
    cout<<*(p)+2<<endl;
    cout<<*(q)+3<<endl;
    cout<<*(q+4)<<endl; // Not possible/we get garbage value as we are trying to fetch the data at 4th index. Which is not there in the array
}