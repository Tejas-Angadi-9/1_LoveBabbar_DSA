#include<bits/stdc++.h>
using namespace std;

void rowWiseSum(int arr[][3]){
    for(int i=0; i<3; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            sum += arr[i][j];
        }
        cout<<"Row "<<i<< ": "<<sum<<endl;
    }
}
void colWiseSum(int arr[][3]){
    for(int i=0; i<3; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            sum += arr[j][i];
        }
        cout<<"Row "<<i<< ": "<<sum<<endl;
    }
}

int main(){
    int arr[3][3] = {{1,2,3}, {5,6,0}, {7,8,7}};
    cout<<"Printing sum row wise"<<endl;
    rowWiseSum(arr);
    cout<<"\nPrinting sum col wise"<<endl;
    colWiseSum(arr);
}