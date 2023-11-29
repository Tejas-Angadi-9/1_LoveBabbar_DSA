#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i] == key)
            return true;
    }
    return false;
}

int main(){
    int arr[] = {2,9,6,7,4,12,15};
    int n = 7, key = 16;
    if(linearSearch(arr, n, key) == 0)
        cout<<"Absent"<<endl;
    else
        cout<<"Present"<<endl;
}

// TC: O(n)     SC: O(1)