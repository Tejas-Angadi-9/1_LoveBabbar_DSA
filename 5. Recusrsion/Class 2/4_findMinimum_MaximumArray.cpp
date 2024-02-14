#include <bits/stdc++.h>
using namespace std;

void findMax(int arr[], int n, int i, int &maxi){
  if(i >= n)
    return ;
  
  if(arr[i] > maxi)
    maxi = arr[i];
  
  findMax(arr, n, i+1, maxi);
}

void findMin(int arr[], int n, int i, int &mini){
  if(i >= n)
    return ;
  
  if(arr[i] < mini)
    mini = arr[i];
  
  findMin(arr, n, i+1, mini);
}

int main() {
  int arr[] = {10,30,15,21,44,26,17};
  int n = 7;
  int maxi = INT_MIN, mini = INT_MAX;

  findMax(arr, n, 0, maxi);
  cout<<"Maximum: "<<maxi<<endl;
  findMin(arr, n, 0, maxi);
  cout<<"Maximum: "<<maxi<<endl;
}