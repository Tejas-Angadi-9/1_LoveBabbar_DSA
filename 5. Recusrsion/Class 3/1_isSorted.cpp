#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n, int i){
  //bc
  if(i == n-1)
    return true;

  // processing
  if(arr[i] > arr[i+1])
    return false;

  // rc
  return isSorted(arr, n, i+1);
}

int main() {
  vector<int> arr {10,20,30,40,20};
  int n = arr.size();
  bool ans = isSorted(arr,n, 0);
  cout<<ans<<endl;
}