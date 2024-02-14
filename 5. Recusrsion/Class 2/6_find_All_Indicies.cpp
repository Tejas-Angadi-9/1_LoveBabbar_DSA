#include <bits/stdc++.h>
using namespace std;

void findAllPosibilites(string &str, char key, int i, vector<int> &ans){
  //bc
  if(i >= str.size())
    return;

  //processing
  if(str[i] == key){
    ans.push_back(i);
  }

  //rc
  findAllPosibilites(str, key, i+1, ans);
}

int main() {
  string str = "babbar";
  char key = 'b';
  vector<int> ans;
  cout<<"Printing all the indices"<<endl;
  findAllPosibilites(str, key, 0, ans);
  for(auto it:ans)
    cout<<it<<" ";
}