#include<bits/stdc++.h>
using namespace std;

// TYPE 1
bool BoolLinearSearch(int arr[][3], int key){
    for(int i=0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j] == key)
                return true;
        }
    }
    return false;
}

// TYPE 2
void linearSearchByIndexes(int arr[][3], int key){
    for(int i=0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(arr[i][j] == key){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

int main(){
    int arr[3][3] = {
        {5,6,8},
        {7,2,4},
        {12,6,9}
    };
    int key = 12;
    
    cout<<BoolLinearSearch(arr, key)<<endl;
    linearSearchByIndexes(arr, key);
}