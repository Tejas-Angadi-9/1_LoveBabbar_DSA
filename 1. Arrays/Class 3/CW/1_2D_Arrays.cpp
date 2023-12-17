#include<bits/stdc++.h>
using namespace std;

void printRowWise(int arr[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printColWise(int arr[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // Initializing the input
    // int arr[3][3] = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };

    int arr[3][3];

    cout<<"Enter the values for 2D Array"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Printing Row wise"<<endl;
    printRowWise(arr);

    cout<<"\nPrinting Column Wise"<<endl;
    printColWise(arr);
}