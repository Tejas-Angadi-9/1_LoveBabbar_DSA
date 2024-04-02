#include <bits/stdc++.h>
using namespace std;

// we need to pass string str by reference and check it why?
int linearSearch(string &str, char key, int i){
  //bc
  if(i >= str.size())
    return -1; // This means we have reached the end of the array and haven't found the value == key

  //processing
  if(str[i] == key)
    return i;

  //rc
  linearSearch(str, key, i+1);
}

int main() {
  string str = "tejas";
  char key = 'j';

  int ans = linearSearch(str, key, 0);
  if(ans<0)
    cout<<key<<" not found"<<endl;
  else
    cout<<"Index: "<<ans<<endl;
}