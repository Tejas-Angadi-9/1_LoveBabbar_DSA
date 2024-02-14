#include<bits/stdc++.h>
using namespace std;

int countingStiars(int n){
  //bc
  if(n == 0 || n == 1)
    return 1;
  
  //rc
  return countingStiars(n-1) + countingStiars(n-2);
}

int main(){
  int n = 5;
  int ans = countingStiars(n);
  cout<<ans<<endl;
}