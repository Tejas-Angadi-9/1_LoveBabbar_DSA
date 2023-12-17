// Print extreme values in an array
#include<bits/stdc++.h>
using namespace std;

void printExtreme(int arr[], int n){
    int i=0, j=n-1;
    while(i<=j){
        if(i==j)
            cout<<arr[i]<<" ";    
        else
            cout<<arr[i]<<" "<<arr[j]<<" ";
            
        i++, j--;
        
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    printExtreme(arr, n);
}

// TC: O(n)     SC: O(1)