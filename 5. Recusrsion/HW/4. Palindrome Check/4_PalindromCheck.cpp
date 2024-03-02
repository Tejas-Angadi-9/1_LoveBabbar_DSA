#include <bits/stdc++.h>
using namespace std;

bool isPali(string &str, int i, int j){
  // bc
  if(i > j) 
    return true;

  // processing
  if(str[i] != str[j])
    return false;

  // rc
  return isPali(str, i+1, j-1);
}

int main() {
  string str = "racecar";
  bool ans = isPali(str, 0, str.size()-1);
  if(ans)
    cout<<"Palindrome"<<endl;
  else
    cout<<"Not a palidrome"<<endl;
}