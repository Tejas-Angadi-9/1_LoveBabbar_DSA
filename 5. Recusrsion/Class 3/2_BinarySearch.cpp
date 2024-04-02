#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int n, int s, int e, int key){
  //bc
  if(s >= e)
    return -1;

  int mid = s+(e-s)/2;

  //processing
  if(arr[mid] == key) return mid;
  else if(arr[mid] > key)
    return binarySearch(arr, n, 0, mid-1, key);
  else
   return binarySearch(arr, n, mid+1, n-1, key);
}

int main() {
  vector<int> arr {1,3,5,7,9,15};
  int n = arr.size(), key = 9;
  cout<<binarySearch(arr, n, 0, n-1, key);
}