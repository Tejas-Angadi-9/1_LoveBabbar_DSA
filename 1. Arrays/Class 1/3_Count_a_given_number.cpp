// Count a number which appears in the array 
#include<bits/stdc++.h>
using namespace std;

int countNumber(int arr[], int n, int num){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == num)
            cnt++;
    }
    return cnt;
}

int main(){
    int arr[] = {2,4,1,6,2,9,2};
    int n = 7, num;
    cout<<"Enter a number to find: ";
    cin>>num;

    cout<<"Frequency of the number: "<<countNumber(arr, n, num);
}

// TC: O(n)     SC: O(1)