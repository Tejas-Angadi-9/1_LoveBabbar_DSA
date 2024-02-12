#include <bits/stdc++.h>
using namespace std;

int findPower(int n){
  //bc
  if(n == 0)  return 1;

  //rr
  int ans = 2 * findPower(n-1);
  return ans;
}

int main() {
  int n = 4;
  int ans = findPower(n);
  cout<<ans<<endl;
}