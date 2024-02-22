#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j){
  //bc
  if(i > j)
    return;

  //processing
  swap(str[i], str[j]);

  //rc
  reverse(str, i+1, j-1);
}

int main() {
  string str = "tejas";
  cout<<"Before reversing: "<<str<<endl;
  reverse(str, 0, str.size()-1);
  cout<<"After reversing: "<<str<<endl;
}