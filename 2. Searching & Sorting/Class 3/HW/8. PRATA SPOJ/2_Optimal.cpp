#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int mid, int p){
  int currentParata = 0;
  for(int i=0; i<arr.size(); i++){
    int R = arr[i], j=1;
    int timeTaken = 0;

    while(true){
      if(timeTaken + j * R <= mid){
        currentParata++;
        timeTaken += j*R;
        j++;
      }else{
        break;
      }
    }
    if(currentParata >= p)  return true;
  }
  return false;
}

int minimumTime(vector<int> arr, int p, int n){
  int highestRank = *max_element(arr.begin(), arr.end());
  int val = highestRank * (p * (p+1)/2);
  int s=0, e = val, ans = -1;
  while(s<=e){
    int mid = s+(e-s)/2;
    if(isPossible(arr, mid, p)){
      ans = mid;
      e = mid - 1;
    }else
      s = mid + 1;
  }
  return ans;
}

int main() {
  int p=10, n=4;
  vector<int> arr {1,2,3,4};
  cout<<minimumTime(arr, p, n)<<endl;
}